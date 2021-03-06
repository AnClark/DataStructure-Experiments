#include<cstdio>
#include<iostream>
using namespace std;

#include "linkedList.cpp"

LinkedListClass *ll = new LinkedListClass();
void llState();
#define ERROR_WARNING cout<<"*** ERROR OCCURRED ***"<<endl

#define TEST_FOR_NEXTELEM

// For debug
int main()
{

    int d, i;

    // TEST FOR CREATE & INSERT
    cout<<"-------- NOW LET'S TEST INSERT --------"<<endl;

    while(cin>>d  &&  d != 0){
        ll->ListInsert(0, d);
    }
    llState();


#ifdef TEST_FOR_REMOVE
    cout<<"-------- NOW LET'S TEST REMOVE --------"<<endl;
    cout<<"\t(-1 for EOL)"<<endl;

    while(cin>>i  &&  i != -1)
    {
        int res = ll->ListDelete(i, d);

        if(res == OK)
            cout<<"--- Removed value: "<<d<<endl;
        else if(res == ERROR)
            ERROR_WARNING;

        llState();
    }
#endif



#ifdef TEST_FOR_GETELEM
    cout<<"-------- NOW LET'S TEST GETELEM --------"<<endl;
    cout<<"\t(-1 for EOL)"<<endl;

    while(cin>>i  &&  i != -1)
    {
        int res = ll->GetElem(i, d);

        if(res == OK)
            printf("Index %d => Value %d \n", i, d);
        else if(res == ERROR)
            ERROR_WARNING;
    }
#endif

#ifdef TEST_FOR_LOCATEELEM
    cout<<"-------- NOW LET'S TEST LOCATEELEM --------"<<endl;
    cout<<"\t(-1 for EOL)"<<endl;

    while(cin>>d  &&  d != -1)
    {
        int res = ll->LocateElem(d);

        if(res)
            printf("Value %d is on address %d \n", d, res);
        else if(res == NULL)
            cout<<"NOT FOUND!";
    }
#endif

#ifdef TEST_FOR_CLEARLIST
    cout<<"-------- LIST WILL BE CLEAR NOW --------"<<endl;
    ll->ClearList();
    
    llState();
#endif

#ifdef TEST_FOR_PRIORELEM
    cout<<"-------- NOW LET'S TEST PRIORELEM --------"<<endl;
    cout<<"\t(-1 for EOL)"<<endl;

    while(cin>>d  &&  d != -1)
    {
        int res;
        ll->PriorElem(d, res);

        if(res)
            printf("Value %d 's prior is %d \n", d, res);
        else if(res == NULL)
            cout<<"*** Not found or ON HEAD!"<<endl;
    }
#endif


#ifdef TEST_FOR_NEXTELEM
    cout<<"-------- NOW LET'S TEST NEXTELEM --------"<<endl;
    cout<<"\t(-1 for EOL)"<<endl;

    while(cin>>d  &&  d != -1)
    {
        int res;
        ll->NextElem(d, res);

        if(res)
            printf("Value %d 's next is %d \n", d, res);
        else if(res == NULL)
            cout<<"*** Not found or ON TAIL!"<<endl;
    }
#endif


    return 0;
}

void llState()
{
    cout<<"Is empty list?\t"<<ll->ListEmpty()<<endl;
    cout<<"Length? \t"<<ll->ListLength()<<endl;

    if(!ll->ListEmpty())
    {
        cout<<"Your linked list is:"<<endl;
        //ll->PrintList();
        ll->ListTrabverse();
    }
}

