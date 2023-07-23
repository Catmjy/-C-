#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

struct student
{
	long num;
	float score;
	struct student *next;
};

struct student *del(struct student *head, long num)
{
	struct student *p1, *p2;
	if(head == NULL)               //�������Ϊ��
	{
		printf("\nlist null!\n");
		return head;
	}
	p1 = head;
	while(p1->num != num && p1->next != NULL)  //����
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(p1->next == NULL) printf("�Ҳ���������\n");  //�Ҳ��������
	else {
	//	printf("\ndelete: %d\n",p1->num);
		p2->next = p1->next;              //ɾ�����ͷſռ�
		free(p1);
	}
	return head;
} 

struct student *create()   //����
{
	
	struct student *end, *tem, *head ;
	head = (struct student*)malloc(sizeof(struct student));
	end = head;
	printf("��������\n");
	for(int i=1; i<=N; i++)
	{
		tem = (struct student*)malloc(sizeof(struct student));
	    scanf("%ld",&tem->num);
		end->next = tem;
		end = tem; 
	}
	end->next = NULL;
	return head;
}

void print(struct student *p)     //���
{
	puts("���µ����ǣ�");
	while(p!= NULL)
	{
		p = p->next;
		printf("%ld ",p->num);
	}	
    return;
}

int main()
{
  long del_num;
  puts("Ҫɾ���������ǣ�");
  scanf("%ld", &del_num);
  
  struct student *head;

  head = create();
  head = del(head, del_num);
  
  print(head);
  return 0;
}  
