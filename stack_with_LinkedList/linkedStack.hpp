#include<iostream>
#include<malloc.h>
using namespace std;

#define nullptr NULL
typedef int ElemType;

struct ListNode
{
    ElemType data;
    ListNode *next;
};

struct LinkedStack
{
    ListNode *top;              // 栈顶指向处在堆栈顶部的元素
    ListNode *bottom;           // 栈底指向链表头结点
};

