#ifndef NODE_H
#define NODE_H
#include "public.h"

// 链表节点类
class Node
{
public:
    Canteen canteen;      // 节点存储的数据
    Node *next = nullptr; // 指向下一个节点的指针

    // 构造函数，初始化节点数据和指针
    Node(Canteen canteenData) : canteen(canteenData), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head; // 使用管理头节点

    // 辅助函数，用于插入新节点
    void insertNode(Node *newNode);

    // 删除指定数据的节点（优化后）
    void deleteNodeInternal(Node *prev, Node *temp, const std::string &canteenName);

public:
    LinkedList();
    ~LinkedList();
    // 其他成员函数...
    void addNode(Canteen canteenData);

    // 删除指定数据的节点（优化前）
    void deleteNode(const std::string &canteenName);

    // 查找节点（优化后，利用traverseAndExecute函数）
    Node *findNode(const std::string &canteenName);

    bool printList( int &number,Canteen & canteen);
};


bool hasCommonCharacter(const std::string str1, const std::string str2) ;

#endif // NODE_H