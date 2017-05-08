#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

/******** Import my linked list library ********/
//TODO: Try to import it as a standard library instead of importing CPP file.
#include "linkedList.cpp"


int main(void){
  LinkedListClass *ll = new LinkedListClass();

  int i, res;

  int op=1;
  while(op){
	system("cls");		// On Windows
	system("clear");	// On Linux
	printf("\n\n");
        printf("      顺序结构链表基本操作演示程序 - 主菜单 \n");
	printf("      Menu for Linked List Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty     10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem       12. ListTrabverse\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~12]:");
	scanf("%d",&op);
	printf("\n\n");
    switch(op){
	   case 1:
                 /** NOTICE: InitList() is called once by constructor. **/
		 if(ll->InitList()==OK) printf("线性表创建成功！\n");
		     else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
                 ll->DestroyList();
		 printf("\n----DestroyList 已经调用！\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 res = ll->ClearList();
		 if(res == OK)
		 	printf("\n----链表已清空！\n");     
		 else
			printf("\n----链表清空失败！\n");
		 getchar();getchar();
		 break;
	   case 4:
                 if(ll->ListEmpty())
		 	printf("\n----当前链表【为空】！\n"); 
		 else
			printf("\n----当前链表【非空】！\n"); 
		 getchar();getchar();
		 break;
	   case 5:
		 printf("\n----链表长度为：%d\n", ll->ListLength());     
		 getchar();getchar();
		 break;
	   case 6:
		 cout<<"----请输入你要检索的元素标号：\t"<<endl;
		 cin>>i;
		 
                 if(ll->GetElem(i, res) == OK)
		 	printf("\n----元素标号 %d ==> 值为 %d\n", i, res);     
		 else
			printf("\n----未找到元素！\n");

		 getchar();getchar();
		 break;
	   case 7:
		 //TODO: Find a way to express a node
		 printf("\n----LocateElem功能待实现！\n");     
		 getchar();getchar();
		 break;
	   case 8:
		 cout<<"----需要查询哪个元素的前驱节点？在此输入：\t"<<endl;
		 cin>>i;
		 
                 if(ll->PriorElem(i, res) == OK)
		 	printf("\n----元素 %d 的前驱结点值为 %d\n", i, res);     
		 else
			printf("\n----操作失败，该元素不在链表中，或为首个结点！\n");
    
		 getchar();getchar();
		 break;
	   case 9:
		 cout<<"----需要查询哪个元素的后继节点？在此输入：\t"<<endl;
		 cin>>i;
		 
                 if(ll->PriorElem(i, res) == OK)
		 	printf("\n----元素 %d 的后继结点值为 %d\n", i, res);     
		 else
			printf("\n----操作失败，该元素不在链表中，或为最后一个结点！\n");
 
		 getchar();getchar();
		 break;
	   case 10:
		 printf("\n----ListInsert功能待实现！\n");     
		 getchar();getchar();
		 break;
	   case 11:
		 printf("\n----ListDelete功能待实现！\n");     
		 getchar();getchar();
		 break;
	   case 12:  
		 if(!ll->ListTrabverse()) printf("*** 线性表是空表！\n");
		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");

  return 0;
}//end of main()


