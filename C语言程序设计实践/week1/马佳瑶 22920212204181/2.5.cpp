#include<stdio.h>
#include<string.h>

 
int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	puts("���֣�"); 
    for(int i = 0; i < strlen(s); ++ i){
    	if(s[i] >= '0' && s[i] <= '9'){
    		++ cnt;
    		printf("%c ", s[i]);
		}
	}
	puts("");
	puts("���ָ�����"); 
	printf("%d", cnt);
	return 0;
}
