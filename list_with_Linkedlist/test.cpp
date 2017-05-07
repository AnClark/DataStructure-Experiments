#include<cstdio>
#include<iostream>
using namespace std;

#include "linkedList.cpp"

LinkedListClass *ll = new LinkedListClass();
void llState();
#define ERROR_WARNING cout<<"*** ERROR OCCURRED ***"<<endl

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


    // TEST FOR REMOVE
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
    

    return 0;
}

void llState()
{
    cout<<"Is empty list?\t"<<ll->ListEmpty()<<endl;
    cout<<"Length? \t"<<ll->ListLength()<<endl;

    if(!ll->ListEmpty())
    {
        cout<<"Your linked list is:"<<endl;
        ll->PrintList();
    }
}

