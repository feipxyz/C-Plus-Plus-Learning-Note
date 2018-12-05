//
// Created by pengfei on 18-12-4.
//
#include "folder.h"
#include <iostream>

using namespace std;


int Folder::m_folder_base = 0;

Message::Message(const Message &m):
m_contents(m.m_contents),
m_folders(m.m_folders)
{
    add_to_folders(m);
}

Message::~Message()
{
    remove_from_folders();
};

Message& Message::operator=(const Message &rhs)
{
    remove_from_folders();
    m_contents = rhs.m_contents;
    m_folders = rhs.m_folders;
    add_to_folders(rhs);

    return *this;
}

void Message::save(Folder &f)
{
    m_folders.insert(&f);   // 将给定的f添加folder集合中
    f.add_msg(this);        // 将本msg添加到folder的msg集合中
}

void Message::remove(Folder &f)
{
    m_folders.erase(&f);    // 将folder从此msg集合中删除
    f.remove_msg(this);     // 反向将message也从folder的集合中删除
}


void Message::add_to_folders(const Message &m)
{
    for (auto f : m.m_folders)
        f->add_msg(this);
}

void Message::remove_from_folders()
{
    // 从保存此msg的所有folder中删除此msg
    for (auto f : m_folders)
        f->remove_msg(this);

    m_folders.clear();      // 将m_folder清空
}

Folder::Folder(const Folder &f):
m_messages(f.m_messages),
m_folder_id(m_folder_base)
{
    m_folder_base++;
    add_to_msgs(f);
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_msgs();
    m_messages = f.m_messages;
    add_to_msgs(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_msgs();
}

void Folder::add_to_msgs(const Folder &f)
{
    // 将这个folder添加到所有msg中
    for (auto msg : f.m_messages)
        msg->add_folder(this);
}

void Folder::remove_from_msgs()
{
    // 将此folder从所有的msg中删除
    while (!m_messages.empty())
        (*m_messages.begin())->remove(*this);
}

void Folder::DebugPrint()
{
    cout << "Folder id: " << m_folder_id << endl;
    for (auto m : m_messages)
    {
        cout << m->m_contents << endl;
    }
    cout << endl;
}

