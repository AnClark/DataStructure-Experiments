#include "seqList.hpp"

status SequentialListClass::InitList()
{
	SQList.elem = malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if (!SQList.elem)
		return OVERFLOW;

	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
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
	e = SQList[i - 1];
	return OK;
}


index SequentialListClass::LocateElem(ElemType e)	// 简化过
{
	if (LISTNULL)
		return ERROR;
    
    int idx=0;
	while(SQList.elem[idx] != e)
	    idx++;
	    
	if(idx >= SQList.length)
	    return INFEASIBLE;
	else
	    return idx;
	    
}


status SequentialListClass::PriorElem(ElemType cur, ElemType & pre_e)
{

}


status SequentialListClass::NextElem(ElemType cur, ElemType & next_e)
{

}


status SequentialListClass::ListInsert(int i, ElemType e)
{

}


status SequentialListClass::ListDelete(int i, ElemType & e)
{

}


// Debug function: print out sequential list
status SequentialListClass::PrintList()
{
	if (LISTNULL)
		return ERROR;

	for (int i = 0; i < SQList.length; i++)
		cout << SQList.elem[i] << "  ";
	cout << endl;

	return OK;
}


status SequentialListClass::ListTrabverse()	// 简化过 
/**** Actually, this function does the same as PrintList() ****/
{
	return PrintList();
}