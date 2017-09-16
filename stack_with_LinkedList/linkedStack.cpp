#include "linkedStack.hpp"

LinkedStack *createStack()
{
    // ����һ���µĶ�ջʵ��
    LinkedStack *stk = new LinkedStack;

    // ���ǵ�������ͷ��㣬��ôջ����Ȼ��ָ�����ͷ���
    // �½�����ʼ��ͷ���
    stk->bottom = new ListNode;
    stk->bottom->data = 0;
    stk->bottom->next = nullptr;

    // ջ��ָ��ָ��ͷ���
    stk->top = stk->bottom;

    // �����¶�ջ
    return stk;
}


bool pushStack(LinkedStack *target_stk, ElemType val)
{
    // ����һ���½��
    ListNode *p = new ListNode;
    p->data = val;
    p->next = nullptr;

    // �漴�Ѹ��½����ӵ���ջ֮��
    target_stk->top->next = p;
    target_stk->top = target_stk->top->next;

    return (target_stk->top != nullptr);
}


ElemType popStack(LinkedStack *target_stk)
{
    ElemType popValue;

    // ���ȶ�λ��ջ�������һ��Ԫ��
    ListNode *i = target_stk->bottom;
    while(i->next != target_stk->top)
        i = i->next;

    // Ȼ���Ƴ�ջ��Ԫ��
    popValue = target_stk->top->data;
    free(target_stk->top);

    // ���ջ��ָ��ָ��ջ�������һ��Ԫ��
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

    info("����һ������ѹ������Ԫ��");
    pushStack(stk, 12); pushStack(stk, 34); pushStack(stk, 56);
    printStack(stk);

    info("���Զ���������������Ԫ��");
    cout<<popStack(stk)<<endl;
    printStack(stk);
    cout<<popStack(stk)<<endl;
    printStack(stk);

    info("����������ѹ������Ԫ��");
    pushStack(stk, 77); pushStack(stk, 88);
    printStack(stk);


}
