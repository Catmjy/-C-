#include<stdio.h>
#include<string.h>

 
int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	
	bool word = true;   //��ǵ�������ĸ 
	
	for(int i = 0; s[i] != '\0'; ++ i){  
		if(s[i] != ' ' && word){  //���ǿո����ǵ�������ĸ 
			++ cnt;
			word = false;  //��ֹ�ظ�ͳ�� 
		}
		else if(s[i] == ' '){  //�ǿո���ѱ������Ϊ�� 
			word = true;
		}
	}
	printf("���ʸ�����");
	printf("%d", cnt);
	
	return 0;
}
