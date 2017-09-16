#include "bidirectionLinkedList.hpp"

void BidirectionalLinkedList::initList()
{
    LHead = new ListNode;

    LHead->next = nullptr;
    LHead->prev = nullptr;
    LHead->data = 0;
}

void BidirectionalLinkedList::destroyList()
{
    // TODO.
}

bool BidirectionalLinkedList::addNode(ElemType val)
{
    ListNode *p = new ListNode;
    p->data = val;
    p->next = nullptr;

    ListNode *i = LHead;
    while(i->next != nullptr)
        i = i->next;

    i->next = p;
    p->prev = i;
}

bool BidirectionalLinkedList::removeNode(ElemType key_val)
{
    ListNode *i = LHead;

    while(i != nullptr  &&  i->data != key_val)
        i = i->next;

    if(i == nullptr) return false;

    i->prev->next = i->next;
    if(i->next != nullptr)
        i->next->prev = i->prev;

    free(i);
}

bool BidirectionalLinkedList::insertNode(ElemType val, ElemType key_val)
{
    // 分类讨论：看看能不能找到插入点。找不到插入点就调用addNode。
    ListNode *i = LHead;

    while(i->next != nullptr  &&  i->data != key_val)
        i = i->next;



    if(i == nullptr)
        addNode(val);

    else
    {
        ListNode *p = new ListNode;
        p->data = val;
        p->next = i->next;
        p->prev = i;

        i->next = p;

    }

}

void BidirectionalLinkedList::printList()
{
    ListNode *i = LHead->next;

    while(i != nullptr)
    {
        cout<< i->data <<'\t';
        i = i->next;
    }

    cout<<endl;
}


#define info(msg) cout<<msg<<endl
int main()
{
    BidirectionalLinkedList lst;
    lst.initList();

    info("TEST1: Add some nodes");
    lst.addNode(123); lst.addNode(456); lst.addNode(789); lst.addNode(987); lst.addNode(654); lst.addNode(321);
    lst.printList();

    info("TEST2: Remove some nodes");
    lst.removeNode(456);
    lst.printList();
    lst.removeNode(399921);
    lst.printList();

    info("TEST3: Add a node after 789");
    lst.insertNode(5555, 789);
    lst.printList();

    info("TEST3 Plus: Fallback to addNode()");
    lst.insertNode(7777, 21651651);
    lst.printList();
}
