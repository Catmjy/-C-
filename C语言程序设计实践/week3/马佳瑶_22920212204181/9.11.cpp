#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STU {
	char xh[20];   //ѧ��
	char name[20];  //����
	struct STU *next;

} COU;


COU *create() { //��������
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	while(1) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%s %s", tem->xh,tem->name);
		if(strcmp(tem->xh, "0") == 0) break;
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *del(COU *head1, char s[]) {
	COU *p = head1->next;
	COU *pre = head1;
	while(p != NULL) {
		if(!strcmp(p->xh, s)) {
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
		printf("%s %s\n",p->xh, p->name);
	}
	return;
}

int main() {
	COU *head1, *head2;
	printf("����������a����0��ʾ����\n");
	head1 = create();                       //��������a
	printf("\n����������b����0��ʾ����\n");
	head2 = create();                     //��������b
	COU *p = head2->next;
	while(p != NULL) {

		head1 = del(head1, p->xh);
		p = p->next;

	}

	print(head1);
	return 0;
}
