/**
    ���Ա�ʵ�ֶ�ջ

    ע�⣺�ڴ����ݽṹ�У�ջ��ָ�򶥲�Ԫ���Ϸ���һ����Ԫ�ء��б���������ʵ�ֵ���һ�����ӡ�
*/

#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;


/** ���Ա����ݽṹ **/
#define LIST_INIT_SIZE 5
#define LIST_INCREMENTIAL_SIZE 5
struct SeqList
{
    ElemType *elem;             // ���Ա�Ļ�ַָ��
    int length;                 // ���Ա�ĵ�ǰ����
    int listSize;               // ���Ա�ǰ����Ŀռ��С
};


/** ���Զ�ջ���ݽṹ **/
struct SeqStack
{
    SeqList *lst;
    int top;
    int bottom;
};
