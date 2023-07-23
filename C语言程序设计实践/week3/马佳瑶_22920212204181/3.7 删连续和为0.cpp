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

	COU *p, *q, *pre;
	

	pre = head1;   //Ҫɾ�Ľڵ��ǰһ����
	p = head1->next;  //����͵ĵ�һ����
	if(p == NULL) return head1;  //������
	q = p->next;
	if(q == NULL) return head1;  //ֻ��һ����
	
	int sum = 0;

	while(1) {
		sum = p->val;
		while(q != NULL) {
			sum += q->val;//printf("%d\n", sum);
			if(sum == 0) {
              //printf("%d %d %d", pre->val, p->val, q->val);
				pre->next = q->next;
				p = pre->next;
				if(p == NULL) break;
				q = p->next;
				sum = p->val;
			} else
				q = q->next;
			
		}
		pre = p;
		if(pre == NULL) break;  //����û������Ŀ���ԭ��NULL->next;
		p = p->next;
		if(p == NULL) break;
		q = p->next;
	}

	return head1;
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
