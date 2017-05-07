#include<iostream>
using namespace std;

#include "linkedList.cpp"

// For debug
int main()
{
    LinkedListClass *ll = new LinkedListClass();

    int d;

    while(cin>>d  &&  d != 0){
        ll->ListInsert(0, d);
    }

    cout<<"Is empty list?\t"<<ll->ListEmpty()<<endl;
    cout<<"Length? \t"<<ll->ListLength()<<endl;

    cout<<"Your linked list is:"<<endl;
    ll->PrintList();

    return 0;
}

