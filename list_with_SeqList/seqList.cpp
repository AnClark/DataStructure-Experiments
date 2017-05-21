#include "seqList.hpp"

status SequentialListClass::InitList()
{
	SQList.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if (!SQList.elem)
		return OVERFLOW;

	SQList.length = 0;
	SQList.listSize = LIST_INIT_SIZE;
	return OK;
}


status SequentialListClass::DestroyList()
{
	free(SQList.elem);
	SQList.elem = NULL;

	SQList.length = 0;
	SQList.listSize = 0;

	// TODO: Find a valid way to check if succeed or not. Try testing null
	// pointer value?
}

status SequentialListClass::ClearList()
{
	if (LISTNULL)
		return ERROR;


	for (int i = 0; i < SQList.length; i++)
		SQList.elem[i] = 0;
	SQList.length = 0;

	return OK;
}


bool SequentialListClass::ListEmpty()
{
	if (LISTNULL)
		return true;

	for (int i = 0; i < SQList.length; i++)
		if (SQList.elem[i] != 0)
			return false;

	return true;
}


int SequentialListClass::ListLength()
{
	if (LISTNULL)
		return ERROR;
	return SQList.length;
}


status SequentialListClass::GetElem(int i, ElemType & e)
// NOTICE: Here we assert that the first index is 1.
{
	e = 0;

	// Situation 1: List is not initialized
	if (LISTNULL)
		return ERROR;

	// Situation 2: Input is out of range, including empty list
	if (i <= 0 || i > SQList.length)
		return INFEASIBLE;

	// Situation 3: Input is right
	e = SQList.elem[i - 1];
	return OK;
}


index SequentialListClass::LocateElem(ElemType e)	// 简化过
{
	if (LISTNULL)
		return ERROR;

	int idx = 0;
	while (SQList.elem[idx] != e)
		idx++;

	if (idx >= SQList.length)
		return INFEASIBLE;
	else
		return idx;

}


status SequentialListClass::PriorElem(ElemType cur, ElemType & pre_e)
{
	if (LISTNULL)
		return ERROR;
}


status SequentialListClass::NextElem(ElemType cur, ElemType & next_e)
{
	if (LISTNULL)
		return ERROR;
}


status SequentialListClass::ListInsert(int i, ElemType e)
// NOTICE: Here we assert that the first index is 1.
{
	if (LISTNULL)
		return ERROR;

	// Check if i illegal or not
	if (i < 1 || i > SQList.length + 1)
		return ILLEGALINPUT;

	// Situation 1: If length >= listsize, we should allocate more spaces first.
	if (SQList.length >= SQList.listSize)
	{
		ElemType *newBase =
			(ElemType * ) realloc(SQList.elem,(SQList.listSize+LISTINCREMENT) * sizeof(ElemType));
		if (!newBase)
			return OVERFLOW;
		SQList.elem = newBase;
		SQList.listSize += LISTINCREMENT;
	}

	// If length<listsize, or after allocating more spaces, we can directly
	// insert.
	int idx = i - 1;
	for (int j = SQList.length - 1; j >= idx; j--)
	{
		SQList.elem[j + 1] = SQList.elem[j];
	}
	SQList.elem[idx] = e;
	SQList.length++;

	return OK;
}


status SequentialListClass::ListDelete(int i, ElemType & e)
{
	if (LISTNULL)
		return ERROR;

    if (ListEmpty())
        return INFEASIBLE;

    // Check if your input illegal or not
    if(i < 1 || i > SQList.length + 1)
        return ILLEGALINPUT;

    // Now start deleting
    // Locate to the item to input, then move
    int j, idx=i - 1;

    // Return the value of item to delete
    e = SQList.elem[idx];

    // Delete procedure
    for(j=idx; j<SQList.length; j++)
        SQList.elem[j] = SQList.elem[j+1];
    SQList.elem[j] = 0;
	SQList.length--;

	return OK;
}


// Debug function: print out sequential list
status SequentialListClass::PrintList()
{
	if (LISTNULL)
		return ERROR;

	if (ListEmpty())
		return FALSE;

	for (int i = 0; i < SQList.length; i++)
		printf("%d  ", SQList.elem[i]);
	printf("\n");

	return OK;
}


status SequentialListClass::ListTrabverse()	// 简化过
/**** Actually, this function does the same as PrintList() ****/
{
	return PrintList();
}
