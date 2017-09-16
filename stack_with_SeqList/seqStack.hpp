/**
    线性表实现堆栈

    注意：在此数据结构中，栈顶指向顶部元素上方的一个空元素。有别于用链表实现的另一个例子。
*/

#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;


/** 线性表数据结构 **/
#define LIST_INIT_SIZE 5
#define LIST_INCREMENTIAL_SIZE 5
struct SeqList
{
    ElemType *elem;             // 线性表的基址指针
    int length;                 // 线性表的当前长度
    int listSize;               // 线性表当前分配的空间大小
};


/** 线性堆栈数据结构 **/
struct SeqStack
{
    SeqList *lst;
    int top;
    int bottom;
};
