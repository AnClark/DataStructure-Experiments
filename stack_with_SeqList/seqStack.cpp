#include "seqStack.hpp"

SeqStack *createStack()
{
    // �Ƚ���һ���µĶ�ջ
    SeqStack *stk = new SeqStack;

    // ��ʼ�����Ա�
    SeqList *lst = new SeqList;
    lst->elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    lst->length = 0;
    lst->listSize = LIST_INIT_SIZE;

    // ��ջ�����Ա��
    stk->lst = lst;

    // ����ջ����ջ��
    stk->top = stk->bottom = 0;

    return stk;
}


bool pushStack(SeqStack *target_stk, ElemType val)
{
    // �����б����뵱ǰ����ռ�ıȽϣ�����������
    // ����һ��ѹ��Ԫ��֮��ԭ��û�����
    if(target_stk->lst->length + 1 <= target_stk->lst->listSize)
    {
        target_stk->lst->elem[target_stk->top] = val;
        target_stk->top++;

    }

    // ���ζ���ѹ��Ԫ��֮��ԭ���������ʱ����Ҫ�����µĿռ�
    else
    {
        // ʹ�� realloc ���·����ڴ�ռ�
        ElemType *newBase = (ElemType* ) realloc(target_stk->lst->elem, (target_stk->lst->listSize + LIST_INCREMENTIAL_SIZE) * sizeof(ElemType));
        target_stk->lst->listSize += LIST_INCREMENTIAL_SIZE;

        target_stk->lst->elem[target_stk->top] = val;
        target_stk->top++;
    }

    target_stk->lst->length++;

    // TODO: ����ֵ������
}

ElemType popStack(SeqStack *target_stk)
{
    ElemType popValue = target_stk->lst->elem[target_stk->top - 1];

    target_stk->lst->elem[target_stk->top - 1] = 0;
    target_stk->top--;

    target_stk->lst->length--;

    return popValue;
}

void printStack(SeqStack *target_stk)
{
    for(int i = 0; i < target_stk->top; i++)
        cout<< target_stk->lst->elem[i] << "\t";

    cout<<endl;
}


#define info(msg) cout<<msg<<endl

int main()
{
    SeqStack *stk = createStack();

    info("����һ������ѹ������Ԫ��");
    pushStack(stk, 12); pushStack(stk, 34); pushStack(stk, 56);
    printStack(stk);

    info("����һplus����ѹ������Ԫ�أ����᲻���Զ�����ռ�");
    pushStack(stk, 111); pushStack(stk, 222); pushStack(stk, 333);
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
