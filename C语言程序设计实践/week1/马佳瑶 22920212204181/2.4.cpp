
#include<stdio.h>
#include<string.h>

 
int main(){
	char a[] = "I love China!";  //������ַ����飬�ǿ��������С�����ַ����Ĵ�С 
	//printf("%d", sizeof(a));
	for(int i = sizeof(a) - 2; i >= 0; -- i) //���һλ����ֹ�� 
	printf("%c", a[i]);  //������a + i ��Ϊ���ǵ����ַ���� ��a + i���ַ��� 
	return 0;
}
