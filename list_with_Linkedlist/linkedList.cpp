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
    Node *p, *q;    //p points to current node to operate, q points to node to delete.

	// Quit if linked list already destroyed
	if(LIST_DESTROYED)
		return ERROR;

    // Init
    p=LHead;

    /******** STAGE 1: Delete nodes with data ********/
    // METHOD: Scan a node, then remove it.
    while(p->next != NULL)
    {
        q=p->next;
        p->next=q->next;
        delete q;
    }

    /******** STAGE 2: Delete header node ********/
    delete LHead;
    LHead = NULL;


    if(!LHead)
        return OK;
    else
        return ERROR;

}


status LinkedListClass::ClearList()
{
    Node *p, *q;    //p points to current node to operate, q points to node to delete.

	// Quit if linked list already destroyed
	if(LIST_DESTROYED)
		return ERROR;

    // Init
    p=LHead->next;

    // Now let's clear list.
    // METHOD: Scan a node, then remove it.
    while(p->next != NULL)
    {
        q=p->next;
        p->next=q->next;
        delete q;
    }

    // Return success level
    if(p->next == NULL)
        return OK;
    else
        return ERROR;
}


bool LinkedListClass::ListEmpty()
{
	if(LIST_DESTROYED)
		return true;
    if(LHead->next->next == NULL)
        return true;
    else
        return false;
}


int LinkedListClass::ListLength()
{
    int len = 0;
    Node *p;
    
	// Quit if linked list already destroyed
	if(LIST_DESTROYED)
		return ERROR;    
    
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


Node* LinkedListClass::LocateElem(ElemType e) //简化过
//NOTICE: I directly return address value in int!
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
    return p;

}


status LinkedListClass::PriorElem(ElemType cur, ElemType & pre_e)
{
    Node *p;    //p points to current node to operate
    pre_e = 0;

    // Return ERROR if linked list is empty
    if(ListEmpty())
        return ERROR;

    // Init
    p=LHead->next;

    // Find out the target node "cur"
    while(p->next != NULL && p->next->data != cur)
        p=p->next;

    // Return ERROR if not found
    if(p->next == NULL)
        return ERROR;


    // Check if target node not the first node
    if(p != LHead->next)
    {
        pre_e = p->data;
        return OK;
    }
    else
    {
        pre_e = 0;
        return FALSE;
    }
    
}


status LinkedListClass::NextElem(ElemType cur, ElemType & next_e)
{
    Node *p;    //p points to current node to operate
    next_e = 0;

    // Return ERROR if linked list is empty
    if(ListEmpty())
        return ERROR;

    // Init
    p=LHead->next->next;

    // Find out the target node "cur"
    while(p != NULL && p->data != cur)
        p=p->next;


    // Return ERROR if not found
    if(p == NULL)
        return ERROR;


    // Check if target node not the first node
    if(p->next != NULL)
    {
        next_e = p->next->data;
        return OK;
    }
    else
    {
        next_e = 0;
        return FALSE;
    }
    
}


status LinkedListClass::ListInsert(int i, ElemType e)
{
    Node *p, *f;       //p points to current node to operate, f refers to new node.
    int j = 0;        //Current ID of node

	//Return INFEASIBLE if linked list is destroyed
	if(LIST_DESTROYED)
		return INFEASIBLE;

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

    if(p->next != NULL)
        return OK;
    else
        return ERROR;
}


status LinkedListClass::ListDelete(int i, ElemType & e)
{
    Node *p, *q;    //p points to current node to operate, q points to node to delete.
    int j = 0;    //Current ID of node

	// Quit if linked list already destroyed
	if(LIST_DESTROYED)
		return ERROR;

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
    
    /*
	if(!q)
        return OK;
    else
        return ERROR;
	*/
	// NOTICE: keyword "delete" will just free the node's space, but not reset its address value!
	return OK;
}


// Debug function: print out linked list
status LinkedListClass::PrintList()
{
    Node *p;      //p points to current node to operate

	//Return INFEASIBLE if linked list is destroyed
	if(LIST_DESTROYED)
		return INFEASIBLE;
  
    //Return error if linked list is empty or destroyed
    if(ListEmpty())
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


status LinkedListClass::ListTrabverse()  //简化过 
/**** Actually, this function does the same as PrintList() ****/
{
    PrintList();
}




