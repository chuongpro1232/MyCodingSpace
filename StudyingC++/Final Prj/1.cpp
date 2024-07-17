#include <iostream>
using namespace std;
class node
{
    int data;
    node *next1;
    node *next2;

public:
    void setNext1(node *ptr) { next1 = ptr; }
    void setNext2(node *ptr) { next2 = ptr; }
    node *getNext1() { return next1; }
    node *getNext2() { return next2; }
    void setData(int dt) { data = dt; }
    int getData() { return data; }
};
int main()
{
    node *head = new node;
    node *ptr = new node;
    head->setData(15);
    head->setNext1(NULL);
    head->setNext2(ptr);
    ptr->setData(10);
    ptr->setNext1(head);
    ptr->setNext2(NULL);
    cout << ptr->getNext1()->getData();
    return 0;
}