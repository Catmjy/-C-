#include<stdio.h>

int main(){
	char s[100];
	scanf("%s", s);
	int cnt = 0;
	bool flag = true;
	for(int i = 0; s[i] != '\0'; ++ i){
		if(s[i] == 'I') ++ cnt;
		else --cnt;
		if(cnt < 0){
			flag = false;
			puts("�Ƿ����У�");
			break;
		}
		//printf("%d\n", cnt);
	}
	if(flag) puts("�Ϸ����У�");
	return 0;
}
