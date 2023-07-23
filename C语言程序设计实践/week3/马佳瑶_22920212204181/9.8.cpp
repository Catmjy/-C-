#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5 

typedef struct STU
{
	int num;
	struct STU *next;
	
}COU; 

COU *create()  //����
{
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	printf("������������\n");
	for(int i=1; i<=N; i++)
	{
		tem = (COU*)malloc(sizeof(COU));
	    scanf("%d",&tem->num);
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

void insert(COU *head, int x)  //����
{
	COU *p1 = head->next;
	COU *p2;
	COU *in = (COU*)malloc(sizeof(COU));	
	in->num = x;
	
	if(x < p1->num)       //����С�������
	{
	  in->next = head->next;
	  head->next = in;
	}
	else
	{
		while(p1->num < x && p1!= NULL)  //�Ҳ���λ��
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p1==NULL) p2->next = in;  //β�������
		else
		{
			in->next = p2->next;   //ͨ������Ĳ���
			p2->next = in;
		}
	}
	return;		
}
void print(COU *p)   //��ӡ���
{
	while(p!= NULL)
	{
		p = p->next;
		printf("%d ",p->num);
	}	
    return;
}
int main()
{
  COU *head;
  int insert_num;	
  head = create();
  printf("���룺\n"); 
  scanf("%d",&insert_num);
  insert(head,insert_num); 
  print(head);
  return 0;
}  
