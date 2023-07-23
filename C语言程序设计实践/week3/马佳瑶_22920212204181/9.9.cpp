#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5 

typedef struct STU
{
	int num;
	struct STU *next;
	
}COU; 

COU *create()   //����
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

void insert(COU *head, int x)  //����x
{
	COU *p1 = head->next;
	COU *p2;
	COU *in = (COU*)malloc(sizeof(COU));	
	in->num = x;
	
	if(x < p1->num)
	{
	  in->next = head->next;
	  head->next = in;
	}
	else
	{
		while(p1->num < x && p1!= NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		
		if(p1==NULL) p2->next = in;
		else
		{
			in->next = p2->next;
			p2->next = in;
		}
	}
	return;		
}

COU *del(COU *head, int num)  //ɾ��num
{
	COU *p1, *p2;
	if(head == NULL)
	{
		printf("\nlist null!\n");
		return head;
	}
	p1 = head->next;
	while(p1->num != num && p1 != NULL) 
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(p1 == NULL) printf("�Ҳ���������\n");
	else {
		p2->next = p1->next;
		free(p1);
	}
	return head;
} 

void print(COU *p)  //��ӡ���
{
	printf("���Ϊ��\n");
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
  int insert_num, delete_num;	
  head = create();
  printf("���룺\n"); 
  scanf("%d",&insert_num);
  insert(head,insert_num); 
  printf("ɾ����\n"); 
  scanf("%d",&delete_num);
  del(head,delete_num); 
  print(head);
  return 0;
}  
 
  
