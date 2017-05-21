/**
  基于单链表存储结构的线性表基本操作
  Basic procedures to manage sequential list

  Basic class definition

  NOTICE: Here we assert that the FIRST INDEX IS 1 when locating items.

*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>


/** STATUS FLAGS TO RETURN **/
#define TRUE 1
#define FALSE 0
#define OK 1                // Success
#define ERROR -256          // Error (Usually when operating an uninitialized list)
#define INFEASIBLE -1       // Target tem not found or unreachable
#define OVERFLOW -2         // Overflow (Usually when fail allocating memory)
#define ILLEGALINPUT -3     // Illegal input


/** Special type definitions **/
typedef int ElemType;
typedef int status;
#define index int


/** Sequential list STRUCT definition **/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
struct SequentialList
{
	ElemType *elem;				// Base addr of storage
	int length;					// Current length
	int listSize;				// Current allocated capacity
};


/** Sequential list CLASS definition **/
class SequentialListClass
{
public:
	// Define a SQList instantation
	SequentialList SQList;

	// Check if list NULL
	#define LISTNULL SQList.elem == NULL

	// Basic operation functions defined in framework
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

