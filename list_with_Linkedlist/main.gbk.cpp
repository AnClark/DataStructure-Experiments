#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

/******** Import my linked list library ********/
//TODO: Try to import it as a standard library instead of importing CPP file.
#include "linkedList.cpp"


int main(void){
  LinkedListClass *ll = new LinkedListClass();

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
        printf("      ˳��ṹ��������������ʾ���� - ���˵� \n");
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
	printf("    ��ѡ����Ĳ���[0~12]:");
	scanf("%d",&op);
	printf("\n\n");
    switch(op){
	   case 1:
                 /** NOTICE: InitList() is called once by constructor. **/
		 if(ll->InitList()==OK) printf("���Ա������ɹ���\n");
		     else printf("���Ա�����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
                 ll->DestroyList();
		 printf("\n----DestroyList �Ѿ����ã�\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 res = ll->ClearList();
		 if(res == OK)
		 	printf("\n----��������գ�\n");     
		 else
			printf("\n----�������ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 4:
                 if(ll->ListEmpty())
		 	printf("\n----��ǰ������Ϊ�ա���\n"); 
		 else
			printf("\n----��ǰ�������ǿա���\n"); 
		 getchar();getchar();
		 break;
	   case 5:
		 printf("\n----��������Ϊ��%d\n", ll->ListLength());     
		 getchar();getchar();
		 break;
	   case 6:
		 cout<<"----��������Ҫ������Ԫ�ر�ţ�\t"<<endl;
		 scanf("%d", &i);
		 
                 if(ll->GetElem(i, res) == OK)
		 	printf("\n----Ԫ�ر�� #%d ==> ֵΪ %d\n", i, res);     
		 else
			printf("\n----δ�ҵ�Ԫ�أ�\n");

		 getchar();getchar();
		 break;
	   case 7:

		 cout<<"----��������Ҫ������Ԫ��ֵ��\t"<<endl;
		 scanf("%d", &d);

		 if(ll->LocateElem(d) != NULL)
			printf("\n----���ҵ�Ԫ�� %d��\n", d);
		 else
			printf("\n----δ�ҵ�Ԫ�أ�\n");
    
		 getchar();getchar();
		 break;
	   case 8:
		 cout<<"----��Ҫ��ѯ�ĸ�Ԫ�ص�ǰ���ڵ㣿�ڴ����룺\t"<<endl;
		 scanf("%d", &i);
		 
                 if(ll->PriorElem(i, res) == OK)
		 	printf("\n----Ԫ�� %d ��ǰ�����ֵΪ %d\n", i, res);     
		 else
			printf("\n----����ʧ�ܣ���Ԫ�ز��������У���Ϊ�׸���㣡\n");
    
		 getchar();getchar();
		 break;
	   case 9:
		 cout<<"----��Ҫ��ѯ�ĸ�Ԫ�صĺ�̽ڵ㣿�ڴ����룺\t"<<endl;
		 scanf("%d", &i);
		 
                 if(ll->NextElem(i, res) == OK)
		 	printf("\n----Ԫ�� %d �ĺ�̽��ֵΪ %d\n", i, res);     
		 else
			printf("\n----����ʧ�ܣ���Ԫ�ز��������У���Ϊ���һ����㣡\n");
 
		 getchar();getchar();
		 break;
	   case 10:
		 isEmptyAtFirst = ll->ListEmpty();

		 if(isEmptyAtFirst)
		 {
			cout<<"��ע�⡿��ǰ����Ϊ�գ����������һ����㡣�����һ������ֵ��"<<endl;
			scanf("%d", &d);

			res = ll->ListInsert(0, d);
			if(res == OK)
					printf("\n----��һ��Ԫ�� %d �ѳɹ����룡\n", d);     
			else if(res == INFEASIBLE)
					printf("\n---�����ѱ����٣���δ��ʼ��������ִ�� InitList! \n", d);     
			else
				printf("\n----Ԫ�� %d ����ʧ�ܣ�\n", d);  
		 }
		 else
		 {
		 	 cout<<"---��������ʼ��������Ԫ�ء������ʽ��Ҫ�����λ��  Ԫ��ֵ"<<endl;
			 scanf("%d%d", &i, &d);

			 if(ll->ListInsert(i, d) == OK)
				printf("\n----Ԫ�� %d �ѳɹ����뵽��� #%d ֮ǰ��\n", d, i);     
			 else
				printf("\n----Ԫ�� %d ����ʧ�ܣ�\n", d);     
		 }

		 getchar();getchar();
		 break;
	   case 11:
		 cout<<"---��������ʼɾ������Ԫ�ء������ʽ��ɾ���Ľ����"<<endl;
		 scanf("%d", &i);

		 if(ll->ListDelete(i, res) == OK)
			printf("\n----�ɹ�ɾ����� #%d����Ԫ�ص�ֵΪ %d��\n", i, res);     
		 else
			printf("\n----��� #%d ɾ��ʧ�ܣ�\n", i);    
  
		 getchar();getchar();
		 break;
	   case 12:  
		 cout<<"================ ��ӡ������Ա� ================"<<endl;
		 res = ll->ListTrabverse();
		 if(!res)
		 	 printf("*** ���Ա��ǿձ���\n");
		 else if(res == INFEASIBLE)
		 	 printf("\n---�����ѱ����٣���δ��ʼ��������ִ�� InitList! \n", d);  
			     
		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

  return 0;
}//end of main()
