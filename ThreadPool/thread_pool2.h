//
// Created by fei peng on 2019-03-16.
//

#ifndef THREADPOOL_THREAD_POOL2_H
#define THREADPOOL_THREAD_POOL2_H

#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <thread>
#include <iostream>

class fixed_thread_pool
{
public:
    explicit fixed_thread_pool(size_t thread_count)
    : data_(std::make_shared<data>())
    {
        for (size_t i = 0; i < thread_count; ++i)
        {
            std::thread(
                    [data = data_]
                    {//工作线程函数
                        std::unique_lock<std::mutex> lk(data->mtx_);
                        for (;;)
                        {
                            if (!data->tasks_.empty())
                            {//如果任务队列非空，获取一个任务并执行
                                auto current = std::move(data->tasks_.front());
                                data->tasks_.pop();
                                lk.unlock();
                                current();
                                lk.lock();
                            }
                            else if (data->is_shutdown_)
                            {//析构时is_shutdown为true，线程退出
                                break;
                            }
                            else
                            {//当前线程阻塞，直到新任务来临时唤醒
                                data->cond_.wait(lk);
                            }
                        }
                    }
            ).detach();
        }
    }

    fixed_thread_pool() = default;
    fixed_thread_pool(fixed_thread_pool&&) = default;

    ~fixed_thread_pool()
    {
        if ((bool) data_)
        {
            {
                std::lock_guard<std::mutex> lk(data_->mtx_);
                data_->is_shutdown_ = true;
            }
            data_->cond_.notify_all();
        }
    }

    template <typename F>
    void execute(F&& task)
    {
        {
            std::lock_guard<std::mutex> lk(data_->mtx_);
            data_->tasks_.emplace(std::forward<F>(task));
        }
        data_->cond_.notify_one();
    }

private:
    struct data{
        std::mutex mtx_;
        std::condition_variable cond_;
        bool is_shutdown_ = false;
        std::queue<std::function<void()>> tasks_;
    };

    std::shared_ptr<data> data_;
};

#endif //THREADPOOL_THREAD_POOL2_H
