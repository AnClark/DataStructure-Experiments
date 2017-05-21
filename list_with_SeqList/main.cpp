#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

/******** Import my linked list library ********/
//TODO: Try to import it as a standard library instead of importing CPP file.
#include "seqList.cpp"


int main(void){
  SequentialListClass *ll = new SequentialListClass();

  // Vars for screen input.
  // i - Index of node in linked list
  // d - Node data
  // res - Result or status value of function
  int i, d, res = 0;
  bool isEmptyAtFirst;

  int op=1;
  while(op){
	system("cls");		// On Windows
	system("clear");	// On Linux
	printf("\n\n");
        printf("      顺序结构线性表基本操作演示程序 - 主菜单 \n");
	printf("      Menu for Sequential List Table On Sequence Structure \n");
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
		 	printf("\n----线性表已清空！\n");
		 else
			printf("\n----线性表清空失败！\n");
		 getchar();getchar();
		 break;
	   case 4:
                 if(ll->ListEmpty())
		 	printf("\n----当前线性表【为空】！\n");
		 else
			printf("\n----当前线性表【非空】！\n");
		 getchar();getchar();
		 break;
	   case 5:
		 printf("\n----线性表长度为：%d\n", ll->ListLength());
		 getchar();getchar();
		 break;
	   case 6:
		 cout<<"----请输入你要检索的元素标号：\t"<<endl;
		 scanf("%d", &i);

         if(ll->GetElem(i, res) == OK)
		 	printf("\n----元素标号 #%d ==> 值为 %d\n", i, res);
		 else
			printf("\n----未找到元素！\n");

		 getchar();getchar();
		 break;
	   case 7:

		 cout<<"----请输入你要检索的元素值：\t"<<endl;
		 scanf("%d", &d);

		 if(ll->LocateElem(d) > 0)
			printf("\n----已找到元素 %d！\n", d);
		 else
			printf("\n----未找到元素！\n");

		 getchar();getchar();
		 break;
	   case 8:
		 cout<<"----需要查询哪个元素的前驱节点？在此输入：\t"<<endl;
		 scanf("%d", &i);

         if(ll->PriorElem(i, res) == OK)
		 	printf("\n----元素 %d 的前驱结点值为 %d\n", i, res);
		 else
			printf("\n----操作失败，该元素不在线性表中，或为首个元素！\n");

		 getchar();getchar();
		 break;
	   case 9:
		 cout<<"----需要查询哪个元素的后继节点？在此输入：\t"<<endl;
		 scanf("%d", &i);

                 if(ll->NextElem(i, res) == OK)
		 	printf("\n----元素 %d 的后继结点值为 %d\n", i, res);
		 else
			printf("\n----操作失败，该元素不在线性中，或为最后一个元素！\n");

		 getchar();getchar();
		 break;
	   case 10:
		 isEmptyAtFirst = ll->ListEmpty();

		 if(isEmptyAtFirst)
		 {
			cout<<"【注意】当前线性表为空，即将插入第一个结点。输入第一个结点的值："<<endl;
			scanf("%d", &d);

			res = ll->ListInsert(1, d);
			if(res == OK)
					printf("\n----第一个元素 %d 已成功插入！\n", d);
			else if(res == ERROR)
					printf("\n---线性表已被销毁，或未初始化。请先执行 InitList! \n", d);
            else if(res == ILLEGALINPUT)
                    printf("\n---输入的i值不合法！\n");
			else
				printf("\n----元素 %d 插入失败！\n", d);
		 }
		 else
		 {
		 	 cout<<"---接下来开始插入线性表元素。输入格式：要插入的位置  元素值"<<endl;
			 scanf("%d%d", &i, &d);

			 if(ll->ListInsert(i, d) == OK)
				printf("\n----元素 %d 已成功插入，参考位置#%d！\n", d, i);
			 else
				printf("\n----元素 %d 插入失败！\n", d);
		 }

		 getchar();getchar();
		 break;
	   case 11:
		 cout<<"---接下来开始删除线性表元素。输入格式：删除的元素标号"<<endl;
		 scanf("%d", &i);

		 switch(ll->ListDelete(i, res))
          {
        case OK:
            printf("\n----成功删除元素 #%d，该元素的值为 %d。\n", i, res);
            break;
        case INFEASIBLE:
            printf("\n---找不到待删除的元素！\n");
            break;
        case ILLEGALINPUT:
            printf("\n---输入的i值不合法！\n");
            break;
        default:
            printf("\n----元素 #%d 删除失败！\n", i);
          }


		 getchar();getchar();
		 break;
	   case 12:
		 cout<<"================ 打印输出线性表 ================"<<endl;
		 res = ll->ListTrabverse();
		 if(res == FALSE)
		 	 printf("*** 线性表是空表！\n");
		 else if(res == ERROR)
		 	 printf("\n---线性已被销毁，或未初始化。请先执行 InitList! \n", d);

		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");

  return 0;
}//end of main()
