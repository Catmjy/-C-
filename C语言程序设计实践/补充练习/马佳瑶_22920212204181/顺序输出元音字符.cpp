#include<stdio.h>
#include<string.h>

const char str[11] = "AEIOUaeiou";  //���峣���ַ��� ��ѭ������ �жϸ�����

char *chg(char *s, char *tmp) {
	int n = strlen(s);
	int j = 0;

	for(int i = 0; i < n; ++ i) {
		for(int k = 0; k < 10; ++ k) {
			if(s[i] == str[k]) {
				tmp[j ++] = s[i];   //�����Ԫ�������tmp�ַ�����
				break;
			}
		}
	}

	tmp[j] = '\0';

	return tmp;
}

int main() {
	char s[15], tmp[15];
	puts("�����ַ�����");
	gets(s);
	puts("���Ϊ��");
	puts(chg(s, tmp));

	return 0;
}
