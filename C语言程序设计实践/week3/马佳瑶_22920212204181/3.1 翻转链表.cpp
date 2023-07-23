#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 7

typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;


COU* reverseList(COU* head) {
	if(head == NULL || head->next == NULL) return head;
	COU *pre, *mid, *end;
	pre = NULL;
	mid = head;
	end = head->next;
    while(1){
		mid->next = pre;       //�޸�ָ��
		if(end == NULL) break;   //��endΪNULLʱ�˳�
		
		pre = mid;              //������������
		mid = end;
		end = end->next;
	}
	
	head = mid;
	return head;
}


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


void print(COU *p, COU *end) {  //��Ϊ����û��ֵ��head��β��㲢����NULL
	printf("��ת���Ϊ��\n");
	while(p != end) {
		printf("%d ",p->val);
		p = p->next;
	}
	return;
}

int main() {
	COU *head1, *head2;
	printf("����������a\n");
	head1 = create();                       //��������a
	head2 = reverseList(head1);
	print(head2, head1);
	return 0;
}
