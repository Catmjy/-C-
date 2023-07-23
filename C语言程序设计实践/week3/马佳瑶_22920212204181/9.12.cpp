#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4

typedef struct STU {
	char xh[20];   //ѧ��
	char name[20];  //����
	char sex[8];  //�Ա�
	int  age;     //����
	struct STU *next;

} COU;


COU *create() { //��������
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	for(int i = 0; i < 4; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%s %s %s %d", tem->xh,tem->name,tem->sex, &tem->age);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *del(COU *head1, int x) {
	COU *p = head1->next;
	COU *pre = head1;
	while(p != NULL) {
		if(p->age == x) {
			pre->next = p->next;
			free(p);
			p = p->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
	return head1;
}

void print(COU *p) {
	printf("\n���Ϊ��\n");
	while(p!= NULL) {
		p = p->next;
		printf("%s %s %s %d\n",p->xh, p->name, p->sex, p->age);
	}
	return;
}

int main() {
	COU *head1;
	printf("������ѧ�š��������Ա�����\n");
	head1 = create();                       //��������a

	int age_k;
	puts("\n������Ҫɾ�������䣺");
	scanf("%d", &age_k);
	head1 = del(head1, age_k);
	
	print(head1);
	return 0;
}
