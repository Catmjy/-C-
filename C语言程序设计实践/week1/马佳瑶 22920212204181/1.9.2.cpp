#include<stdio.h>   //ͨ��ָ�봫��ַ��Ӹı�ֵ

#define N 12

void fac(int *n){
	int sum = 1;
	for(int i = *n; i >= 1; -- i){
		sum *= i;
	}
	*n = sum;
}
 
int main( )
{ 
  int m;
  float k;
  printf("input m:");
  scanf("%d",&m);
  
  fac(&m);
  k = m;
  
  printf("result=%f",k);
}
