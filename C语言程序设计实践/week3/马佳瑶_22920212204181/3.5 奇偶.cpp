#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

COU *head1, *head2;

COU *create() { //��������
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	int len;
	printf("�����������ȣ�");
	scanf("%d", &len);	
	printf("����������a\n");
	for(int i = 0; i < len; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *edit(COU *head1) {

	COU *head, *mid, *end;
	head = (COU*)malloc(sizeof(COU));
	if(head1->next == NULL) return head;
	mid = head;

	COU *p = head1->next;
	while(1) {                          //������
		end = (COU*)malloc(sizeof(COU));
		end->val =  p->val;
		mid->next = end;
		mid = end;
		p = p->next;
		if(p == NULL) break;       //����������NULL�ͽ���
		p = p->next;
		if(p == NULL) break;
		//puts("**");
	}
	p = head1->next;
	p = p->next;
	while(1) {
		end = (COU*)malloc(sizeof(COU));   //��ż��
		end->val =  p->val;
		mid->next = end;
		mid = end;
		p = p->next;
		if(p == NULL) break;
		p = p->next;
		if(p == NULL) break;
		//puts("***");
	}
    mid->next = NULL;
    return head;
}

void print(COU *p) {
	printf("���Ϊ��\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}


int main() {

	head1 = create();                       //��������a
	head2 = edit(head1);

	print(head2);
	return 0;
}
