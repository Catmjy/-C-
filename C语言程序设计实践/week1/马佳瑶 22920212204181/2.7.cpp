#include<stdio.h>
#include<string.h>

 
int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	
	for(int i = 0; s[i] != '\0'; ++ i){
		if(s[i] == 't'){
			s[i] = 'e'; ++ cnt;
		} 
		else if(s[i] == 'T'){
			s[i] = 'E'; ++ cnt;
		}
	} 
	puts("�滻����ַ�����");
	puts(s); 

	printf("�滻������");
	printf("%d", cnt);
	
	return 0;
}
