#include<stdio.h>

int main() {
	int x;
	
	scanf("%d", &x);
	
	unsigned i = 1 << 31;  //��int�����λ��ʼ����31����32��
	
	for(; i; i >>= 1){  //ÿ�������ƶ�һλ����Ҫ���ǵ��ںţ�
		printf("%d", x & i ? 1 : 0);  //�����λ��1������������0����ʵ�����֣�
	}

	return 0;
}
