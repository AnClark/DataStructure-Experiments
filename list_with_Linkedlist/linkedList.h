/**
  基于单链表存储结构的线性表基本操作

  NOTICE: This linked list has LEADING NODE.
  
  Basic class definition
*/

#include<stdio.h>
#include<string.h>
//#include<malloc.h>
//#include<math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int ElemType;
typedef int status;

class LinkedListClass
{
private:
struct Node
{
    ElemType data;
    Node *next;
};

public:

// Header Pointer
Node *LHead;

// Basic operation functions
status InitList();
status DestroyList();
status ClearList();
bool ListEmpty();
int ListLength();

status GetElem(int i,ElemType & e);
int LocateElem(ElemType e); //简化过
status PriorElem(ElemType cur, ElemType & pre_e);
status NextElem(ElemType cur, ElemType & next_e);
status ListInsert(int i, ElemType e);
status ListDelete(int i, ElemType & e);
status ListTrabverse();  //简化过

// Extra features
status PrintList();


// Constructor & Deconstructor
LinkedListClass(){
	InitList();
}

~LinkedListClass(){
	DestroyList();
}

};



