//Include iostream for debug only
#include<iostream>
using namespace std;
//--------------------------------------

#include "linkedList.h"

status LinkedListClass::InitList(){
    LHead = new Node;

    Node *leading = new Node;
    leading->data = 0;
    leading->next = NULL;
    LHead->next = leading;
    
    if(LHead)
        return OK;
    else
        return ERROR;
}


status LinkedListClass::DestroyList(){
    

}

status LinkedListClass::ClearList(){}


bool LinkedListClass::ListEmpty()
{
    if(LHead->next->next == NULL)
        return true;
    else
        return false;
}


int LinkedListClass::ListLength()
{
    int len = 0;
    Node *p;
    p=LHead->next->next;

    while(p != NULL){
        p=p->next;
        i++;
    }

    return len;
}


status LinkedListClass::GetElem(int i,ElemType & e){}


status LinkedListClass::LocateElem(ElemType e) //简化过
{}

status LinkedListClass::PriorElem(ElemType cur, ElemType & pre_e){}

status LinkedListClass::NextElem(ElemType cur, ElemType & next_e){}

status LinkedListClass::ListInsert(int i, ElemType e){}

status LinkedListClass::ListDelete(int i, ElemType & e){}

status LinkedListClass::ListTrabverse()  //简化过
{}


int main()
{
    LinkedListClass *ll = new LinkedListClass();

    int res = ll->InitList();

    cout<<res;

    return 0;
}

