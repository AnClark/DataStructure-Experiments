/**
  基于单链表存储结构的线性表基本操作
  Basic procedures to manage sequential list

  Basic class definition
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -256
#define INFEASIBLE -1
#define OVERFLOW -2
#define ILLEGALINPUT -3

typedef int ElemType;
typedef int status;
#define index int

// Sequential list definition
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
struct SequentialList
{
	ElemType *elem;				// Base addr of storage
	int length;					// Current length
	int listSize;				// Current allocated capacity
};

class SequentialListClass
{

  public:

	// Define a SQList instantation
	SequentialList SQList;

	// Check if list NULL
	#define LISTNULL SQList.elem == NULL

	// Basic operation functions
	status InitList();
	status DestroyList();
	status ClearList();
	bool ListEmpty();
	int ListLength();

	status GetElem(int i, ElemType & e);
	index LocateElem(ElemType e);	// 简化过
	status PriorElem(ElemType cur, ElemType & pre_e);
	status NextElem(ElemType cur, ElemType & next_e);
	status ListInsert(int i, ElemType e);
	status ListDelete(int i, ElemType & e);
	status ListTrabverse();		// 简化过

	// Extra features
	status PrintList();


	// Constructor & Deconstructor
	  SequentialListClass()
	{
		InitList();
	}

	 ~SequentialListClass()
	{
		DestroyList();
	}

};

