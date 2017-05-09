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
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType;
typedef int status;

struct Node
{
    ElemType data;
    Node *next;
};

class LinkedListClass
{

public:

// Header Pointer
Node *LHead;

// Check if list destroyed or not initialized
#define LIST_DESTROYED (LHead == NULL)

// Basic operation functions
status InitList();
status DestroyList();
status ClearList();
bool ListEmpty();
int ListLength();

status GetElem(int i,ElemType & e);
Node* LocateElem(ElemType e); //简化过
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



