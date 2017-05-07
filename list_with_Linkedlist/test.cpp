#include<cstdio>
#include<iostream>
using namespace std;

#include "linkedList.cpp"

LinkedListClass *ll = new LinkedListClass();
void llState();

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
    while(cin>>i  &&  i != -1){
        ll->ListDelete(i, d);
        cout<<"--- Removed value: "<<d<<endl;
        llState();
    }
    

    return 0;
}

void llState()
{
    cout<<"Is empty list?\t"<<ll->ListEmpty()<<endl;
    cout<<"Length? \t"<<ll->ListLength()<<endl;

    cout<<"Your linked list is:"<<endl;
    ll->PrintList();
}
