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
        len++;
    }

    return len;
}


status LinkedListClass::GetElem(int i,ElemType & e)
{
    Node *p;    //p points to current node to operate
    int j = 0;        //Current ID of node

    // Return error if list is empty
    if(ListEmpty())
        return ERROR;

    // Init
    p=LHead->next->next;

    // Now let's find out the node!
    while(p != NULL && j < i)
    {
        p=p->next;
        j++;
    }

    // Return false if not found
    if(p == NULL)
        return FALSE;
    
    // Output target to var "e"
    e = p->data;
    return OK;
}


int LinkedListClass::LocateElem(ElemType e) //简化过
//NOTICE: I directly return address value in int!
//       G++ on Ubuntu 13.10 doesn't support treating a struct as return type!
{
    Node *p;    //p points to current node to operate

    // Return NULL pointer if list is empty
    if(ListEmpty())
        return ERROR;

    // Init
    p=LHead->next->next;

    // Now let's find out the node!
    while(p != NULL && p->data != e)
        p=p->next;

    // Return NULL pointer if not found
    if(p == NULL)
        return NULL;

    // Return target node's pointer if succeed
    return (int) p;

}


status LinkedListClass::PriorElem(ElemType cur, ElemType & pre_e){}

status LinkedListClass::NextElem(ElemType cur, ElemType & next_e){}


status LinkedListClass::ListInsert(int i, ElemType e)
{
    Node *p, *f;       //p points to current node to operate, f refers to new node.
    int j = 0;        //Current ID of node

    //Init
    p=LHead->next;

    /******** Situation 1: Insert into an empty list ********/
    // If list is empty, force insert one node regardless of value of i
    if(p->next == NULL)
    {

        f = new Node;
        f->data = e;
        f->next = p->next;
        p->next = f;

        goto exit;
    }

    /******** Situation 2: Insert into a non-empty list ********/

    //Find somewhere to insert
    while(p->next != NULL && j < i)
    {
        p=p->next;
        j++;
    }

    //Return false if nowhere can insert
    if(p->next == NULL)
        return FALSE;

    // Now let's insert
    f = new Node;
    f->data = e;
    f->next = p->next;
    p->next = f;

exit:

    if(f)
        return OK;
    else
        return ERROR;
}


status LinkedListClass::ListDelete(int i, ElemType & e)
{
    Node *p, *q;    //p points to current node to operate, q points to node to delete.
    int j = 0;    //Current ID of node

    //Init
    p=LHead->next;

    //Find out the node to delete
    while(p->next != NULL && j < i)
    {
        p=p->next;
        j++;
    }

    //Return false if the node for delete not found
    if(p->next == NULL)
        return FALSE;

    //Now let's delete
    q = p->next;
    p->next = q->next;
    e=q->data;      // Dump the node's value to var "e"
    delete q;
    
    if(!q)
        return OK;
    else
        return ERROR;
}

status LinkedListClass::ListTrabverse()  //简化过
{}



// Debug function: print out linked list
status LinkedListClass::PrintList()
{
    Node *p;      //p points to current node to operate
   
    //Return error if linked list is empty
    if(LHead->next->next == NULL)
        return ERROR;
 
    //Init
    p=LHead->next->next;

    //Now let's print!
    while(p != NULL){
        cout<< p->data <<'\t';
        p=p->next;
    }
    cout<<endl;

    // Return OK if succeed
    return OK;
}





