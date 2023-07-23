#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} COU;

int n;

COU* reverseList(COU* head) {
	
	COU *pre, *mid, *end;
	pre = head->next;
	mid = pre->next;
	end = mid->next;
	pre->next = NULL;
	while(1) {
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
	printf("�����������ȣ�");
	scanf("%d", &n);
	printf("����������\n");
	for(int i = 0; i < n; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d", &tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}


//void print(COU *p) {  
//
//	while(p != NULL) {
//		printf("%d ",p->val);
//		p = p->next;
//	}
//	return;
//}

COU *cpy(COU *head1){
	COU *head2, *mid, *end, *p;
	p = head1->next;
	head2 = (COU*)malloc(sizeof(COU));
	mid = head2;
	while(p != NULL){
		end = (COU*)malloc(sizeof(COU));
		end->val = p->val;                   //����
		p = p->next;
		mid->next = end;
		mid = end;
	}
	
	mid->next = NULL;
	
//	COU *q = head2->next;
//	printf("%d\n",q->val);puts("***");

	return head2->next;
}

bool check(COU *p, COU *q){	
	while(p != NULL){
	//printf("%d %d\n", p->val, q->val);
		if(p->val != q->val) return false;   //������ͬ�򷵻�false
		p = p->next, q = q->next;
	}
	return true;
}


int main() {
	COU *head1, *head2;
	
	head1 = create();  //��������
	
	if(n < 2) puts("true");  //ֻ��1����
	else if(n < 3){          //ֻ��2����
		COU *a = head1->next, *b = a->next;
		if(a->val != b->val) puts("false");
		else puts("true");
	}
	else{
		head2 = cpy(head1); //printf("%d\n",head2->val);  //������1���Ƶ�����2
		head1 = reverseList(head1);     //��ת����1
		
		if(check(head1, head2)) puts("true");  //�������1������2��ȣ����ǻ��Ĵ�
		else puts("false");
	}

	return 0;
}
