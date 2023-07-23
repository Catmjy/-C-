#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 13 

typedef struct YSF    //����ʵ��Լɪ������
{
	int num;
	struct YSF *next;
	
}COU; 

COU *create()   //��������
{
	COU *pre, *tem, *head;
	head = (COU*)malloc(sizeof(COU));  //ͷ�������ռ�
	pre = head;                     //�ý����ͷ��㴦��ͬһλ��
	for(int i=1; i<=N; i++)
	{
		tem = (COU*)malloc(sizeof(COU));   //��ʱ��������ռ�
	    tem->num = i;                    //��ֵ
		pre->next = tem;                //ָ��
		pre = tem;                       //����
	}
	pre->next = tem;
	return head;
}

void quit(COU *head)
{
	int tol = N;
	COU *p = head;
    COU *q;
	while(tol > 1)   //��ǰʣ������
	{
		int cnt = 1;
		while(cnt < 3)  //�����ƶ�
		{
			++cnt;	
		    q = p;
			p = p->next;
		}
		q->next = p->next;  //ɾ������3�ĵ�
		free(p);         //�ͷſռ�
		p = q->next;    //�����
		tol--;            //����-1
	}
	printf("ʣ�µ�����:\n");
	printf("%d", p->num);
	return;
}

int main()
{
  COU *head;	
  head = create();    //��������
  quit(head);        //Լɪ��
  
  return 0;
}  
