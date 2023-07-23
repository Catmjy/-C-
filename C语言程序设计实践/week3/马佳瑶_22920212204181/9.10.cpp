#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU
{
	char xh[20];   //ѧ��
	double score;  //����
	struct STU *next;  
	
}COU; 
 

COU *create()   //��������
{
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	while(1)
	{
		tem = (COU*)malloc(sizeof(COU));
	    scanf("%s %lf",tem->xh,&tem->score);
	    if(tem->score == 0) break;
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

COU* merge(COU* a, COU *b)
{
	COU* head = (COU*)malloc(sizeof(COU));
	a = a->next;
	b = b->next;	
	COU *end = (COU*)malloc(sizeof(COU));
	end = head;
	while(a!=NULL && b!=NULL)
	{
		if(strcmp(a->xh, b->xh) < 0)  //��ѧ��aС��ѧ��b������a
		{
			end->next = a;
			end = a;
			a = a->next;
		}
		else                  //��ѧ��b���ڵ���ѧ��a������b
		{
		    end->next = b;
			end = b;
			b = b->next;	
		}
		
	}	
	
		if(a==NULL)   //��a��β����ʱ��
		{
			while(b!=NULL)  //���b����ʣ��
			{
				end->next = b;
				end = b;
				b = b->next;
			}
		}
		else     //��b��β����ʱ��
		{
			while(a!=NULL)   //���a����ʣ��
			{
				end->next = a;
				end = a;
				a = a->next;
			}
		}
		end->next = NULL;
    return head;
}

void print(COU *p)
{
	printf("�ϲ����Ϊ��\n");
	while(p!= NULL)
	{
		p = p->next;
		printf("%s %lf\n",p->xh, p->score);
	}	
    return;
}

int main()
{
  COU *head1, *head2, *head;
  printf("����������a����0��ʾ����\n");
  head1 = create();                       //��������a
  printf("����������b����0��ʾ����\n");
  head2 = create();                     //��������b
  head = merge(head1, head2); 
  print(head);
  return 0;
}  
