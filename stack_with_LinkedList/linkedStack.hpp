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
    ListNode *top;              // ջ��ָ���ڶ�ջ������Ԫ��
    ListNode *bottom;           // ջ��ָ������ͷ���
};

