#include <iostream>
#include <../include/node.h>

LinkedList::LinkedList()
{
    // head->next=nullptr;
}

LinkedList::~LinkedList()
{
    Node *current = head;
    Node *next;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

// 辅助函数，用于插入新节点
void LinkedList::insertNode(Node *newNode)
{
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 删除指定数据的节点（优化后）
void LinkedList::deleteNodeInternal(Node *prev, Node *temp, const std::string &canteenName)
{
    if (temp != nullptr && temp->canteen.getName() == canteenName)
    {
        if (prev == nullptr) // 如果是头节点
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        temp = nullptr; // 防止悬空指针
    }
}

// 其他成员函数...
void LinkedList::addNode(Canteen canteenData)
{
    Node *newNode = new Node(canteenData);
    insertNode(newNode);
}

// 删除指定数据的节点（优化前）
void LinkedList::deleteNode(const std::string &canteenName)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->canteen.getName() == canteenName)
        {
            deleteNodeInternal(prev, temp, canteenName);
            break; // 找到并删除后跳出循环
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Node with name " << canteenName << " not found." << std::endl;
    }
}

// 查找节点
Node *LinkedList::findNode(const std::string &canteenName)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->canteen.getName() == canteenName)
        {
            return temp; // 找到节点，返回指针
        }
        temp = temp->next;
    }
    return nullptr; // 未找到，返回nullptr
}

bool LinkedList::printList(int &number, Canteen &canteen)
{
    Node *temp = head;
    int n = 0;
    if (number == 0)
    {
        canteen = temp->canteen;
        return true;
    }
    while (temp != nullptr && n < number)
    {

        temp = temp->next;
        canteen = temp->canteen;
        n++;
    }
    if (n == number)
    {
        number = -1;
        return true;
    }
}

bool hasCommonCharacter(const std::string str1, const std::string str2) {
    for (char c : str1) {
        if (str2.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

