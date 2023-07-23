#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 7

typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

COU *head1;

COU *create() { //��������
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	for(int i = 0; i < N; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

void print(COU *p) {
	printf("ȥ�ؽ��Ϊ��\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}

void del(COU *pre, int x) {
	COU *p = pre->next;
	while(p != NULL) {
		if(p->val == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;  //p=p->next�Ǵ��
		} else {
			pre = p;
			p = p->next;
		}
		//print(head1);
	}

}



int main() {
	printf("����������a\n");
	head1 = create();                       //��������a
	COU *p = head1->next;
	while(p != NULL) {
		del(p, p->val);   //�ӽڵ�p��ʼ�������ҵ���pһ�������ֲ�ɾȥ
		p = p->next;
		//printf("%d\n", p->val);
	}
	
	print(head1);
	return 0;
}
