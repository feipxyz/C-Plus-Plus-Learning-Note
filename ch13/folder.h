//
// Created by pengfei on 18-12-4.
//

#ifndef CH12_FORLDER_H
#define CH12_FORLDER_H

#include <vector>
#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
public:
    explicit Message(const std::string &str = ""): m_contents(str) {}
    Message(const Message&);                //拷贝构造函数
    Message& operator=(const Message&);     //拷贝赋值运算符
    Message(Message &&);                    //移动构造函数
    Message& operator=(Message&&);          //移动赋值运算符

    ~Message();

    //从给定Folder添加/删除本Message
    void save(Folder&);
    void remove(Folder&);

private:
    std::string m_contents;         // 实际的消息文本
    std::set<Folder*> m_folders;    // 包含本message的folder

    void add_to_folders(const Message&);
    void remove_from_folders();

    // Folder类用来将自身加入到Message的Folder中
    void add_folder(Folder *f) { m_folders.insert(f); }
    void move_folders(Message*);
};

class Folder
{
    friend class Message;
public:
    Folder(): m_folder_id(m_folder_base) { m_folder_base++; }
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void DebugPrint();

private:
    static int m_folder_base;            //用来控制id自增
    int m_folder_id;                    //每个folder独一无二的id
    std::set<Message*> m_messages;      //此foldr下所有的message

    void add_to_msgs(const Folder&);    //将这个folder添加到每个message中
    void remove_from_msgs();            //从每个msg中移除这个folder
    void add_msg(Message *m) { m_messages.insert(m); }
    void remove_msg(Message *m) { m_messages.erase(m); }
};


#endif //CH12_FORLDER_H
