#include<stdio.h>
#include<string.h>

 
int main(){
	char a[50] = "I love ";  //���ַ�������ʽ��������ռ� �����޷�ʵ�� 
	char b[] = "China";
	strcat(a, b);
	puts(a);
	return 0;
}
