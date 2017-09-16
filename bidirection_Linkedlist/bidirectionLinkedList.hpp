#include<iostream>
#include<malloc.h>
#include<cstdlib>
using namespace std;

typedef int ElemType;


struct ListNode
{
    ElemType data;
    ListNode *prev;
    ListNode *next;
};


class BidirectionalLinkedList
{
private:
    ListNode *LHead;

public:
    void initList();
    void destroyList();

    bool addNode(ElemType val);
    bool insertNode(ElemType val, ElemType key_val);
    bool removeNode(ElemType key_val);
    void printList();

    BidirectionalLinkedList(){initList();}
    ~BidirectionalLinkedList(){destroyList();}
};
