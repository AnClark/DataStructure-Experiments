#include "linkedStack.hpp"

LinkedStack *createStack()
{
    // 建立一个新的堆栈实例
    LinkedStack *stk = new LinkedStack;

    // 我们的链表有头结点，那么栈底自然就指向这个头结点
    // 新建并初始化头结点
    stk->bottom = new ListNode;
    stk->bottom->data = 0;
    stk->bottom->next = nullptr;

    // 栈顶指针指向头结点
    stk->top = stk->bottom;

    // 返回新堆栈
    return stk;
}


bool pushStack(LinkedStack *target_stk, ElemType val)
{
    // 建立一个新结点
    ListNode *p = new ListNode;
    p->data = val;
    p->next = nullptr;

    // 随即把该新结点添加到堆栈之中
    target_stk->top->next = p;
    target_stk->top = target_stk->top->next;

    return (target_stk->top != nullptr);
}


ElemType popStack(LinkedStack *target_stk)
{
    ElemType popValue;

    // 首先定位到栈顶下面第一个元素
    ListNode *i = target_stk->bottom;
    while(i->next != target_stk->top)
        i = i->next;

    // 然后移除栈顶元素
    popValue = target_stk->top->data;
    free(target_stk->top);

    // 最后将栈顶指针指向栈顶下面第一个元素
    target_stk->top = i;
    target_stk->top->next = nullptr;

    return popValue;
}


void printStack(LinkedStack *target_stk)
{
    ListNode *i = target_stk->bottom->next;

    while(i != nullptr) {
        cout<< i->data << "\t";
        i = i->next;
    }

    cout<<endl;
}

#define info(msg) cout<<msg<<endl

int main()
{
    LinkedStack *stk = createStack();

    info("测试一：连续压入三个元素");
    pushStack(stk, 12); pushStack(stk, 34); pushStack(stk, 56);
    printStack(stk);

    info("测试二：连续弹出两个元素");
    cout<<popStack(stk)<<endl;
    printStack(stk);
    cout<<popStack(stk)<<endl;
    printStack(stk);

    info("测试三：再压入两个元素");
    pushStack(stk, 77); pushStack(stk, 88);
    printStack(stk);


}
