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
	printf("ȥ�ظ������Ϊ��\n");
	while(p != NULL) {
		p = p->next;
		printf("%d ",p->val);
	}
	return;
}

void del(COU *pre) {
	COU *mid = pre->next, *end = mid->next;  //pre���ظ����ֵ�ǰһ����end���ظ����ֵĺ�һ��
	if(mid == NULL || end == NULL) return;    //�������ֻ��һ���������

	while(1) {
		while(mid->val == end->val){
			end = end->next;
			if(end == NULL) break;    //��endΪNULLʱҪ�˳�������ĩλ���ظ����ֻ����
		} 
		if(mid->next != end) {    //�����ظ������
			while(mid != end) {
				pre->next = mid->next;
				free(mid);
				mid = pre->next;
			}
		}else{                //û���ظ���ȫ������
			pre = mid;
			mid = end;
		}
		if(mid == NULL) break; //�߽�
		end = end->next;
		if(end == NULL) break;//printf("%d %d %d\n", pre->val, mid->val, end->val);
		//print(head1); 
		//puts("****");
		
	}
	//print(head1);
	return;
}



int main() {
	printf("����������a\n");
	head1 = create();                       //��������a
	del(head1);

	print(head1);
	return 0;
}
