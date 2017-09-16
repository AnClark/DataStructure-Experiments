#include "seqStack.hpp"

SeqStack *createStack()
{
    // 先建立一个新的堆栈
    SeqStack *stk = new SeqStack;

    // 初始化线性表
    SeqList *lst = new SeqList;
    lst->elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    lst->length = 0;
    lst->listSize = LIST_INIT_SIZE;

    // 将栈与线性表绑定
    stk->lst = lst;

    // 设置栈顶和栈底
    stk->top = stk->bottom = 0;

    return stk;
}


bool pushStack(SeqStack *target_stk, ElemType val)
{
    // 根据列表长度与当前分配空间的比较，分情形讨论
    // 情形一：压入元素之后，原表没有溢出
    if(target_stk->lst->length + 1 <= target_stk->lst->listSize)
    {
        target_stk->lst->elem[target_stk->top] = val;
        target_stk->top++;

    }

    // 情形二：压入元素之后，原表溢出。这时就需要分配新的空间
    else
    {
        // 使用 realloc 重新分配内存空间
        ElemType *newBase = (ElemType* ) realloc(target_stk->lst->elem, (target_stk->lst->listSize + LIST_INCREMENTIAL_SIZE) * sizeof(ElemType));
        target_stk->lst->listSize += LIST_INCREMENTIAL_SIZE;

        target_stk->lst->elem[target_stk->top] = val;
        target_stk->top++;
    }

    target_stk->lst->length++;

    // TODO: 返回值。。。
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

    info("测试一：连续压入三个元素");
    pushStack(stk, 12); pushStack(stk, 34); pushStack(stk, 56);
    printStack(stk);

    info("测试一plus：再压入三个元素，检查会不会自动申请空间");
    pushStack(stk, 111); pushStack(stk, 222); pushStack(stk, 333);
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
