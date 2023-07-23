#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Link {
	int val;
	struct Link *next;

} COU;


COU *create() { //��������
	COU *end, *tem, *head;
	head = (COU*)malloc(sizeof(COU));
	end = head;
	puts("����������ĳ��ȣ�");
int n;
	scanf("%d", &n);
	printf("����������\n");
	for(int i = 0; i < n; ++ i) {
		tem = (COU*)malloc(sizeof(COU));
		scanf("%d",&tem->val);
		end->next = tem;
		end = tem;
	}
	end->next = NULL;
	return head;
}

COU *cpy(COU *head1) {
	COU *head2, *mid, *end, *p;
	head2 = (COU*)malloc(sizeof(COU));
	mid = head2;
	p = head1->next;
	while(p != NULL) {
		end = (COU*)malloc(sizeof(COU));
		end->val = p->val;
		p = p->next;
		mid->next = end;
		mid = end;
	}
	mid->next = NULL;
	return head2;
}

COU *reverse(COU *head) {
	COU *pre, *mid, *end;
	pre = head->next;
	mid = pre->next;
	end = mid->next;
	pre->next = NULL;
	
	while(1){
		mid->next = pre;
		if(end == NULL) break;
		pre = mid;
		mid = end;
		end = end->next;
	}printf("%d\n", mid->val);
	head = end;
	head->next = mid;
	
	return head;
}

bool check(COU *head1, COU *head2) {
	COU *p, *q;
	p = head1->next, q = head2->next;
	while(p != NULL) {
		if(p->val != q->val) return false;
		p = p->next;
		q = q->next;
	}
	return true;
}


int main() {
	COU *head1, *head2;
	head1 = create();  //��������a
	
	if(n < 2) puts("true");       //ֻ��һ�����
	else if(n < 2) {              //ֻ���������
		
		COU *a = head1->next, *b = a->next;
		if(a->val == b->val) puts("true");
		else puts("false");
		
	} else {
		
		head2 = cpy(head1);            //��������1
		head2 = reverse(head2);         //��ת

		if(check(head1, head2)) puts("true");
		else puts("false");

	}

	return 0;
}
