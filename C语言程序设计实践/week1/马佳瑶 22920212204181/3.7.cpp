#include <stdio.h>
#include <string.h>
#include <math.h>

char str[42], s[40];


int main() {
	gets(str);
	int n = 0;

    for(int i = 0; str[i] != '\0'; ++ i){  //ȥ���ո�
		if(str[i] != ' '){
			s[n ++] = str[i];
		}
	}
	
	if(s[0] == '1') printf("-");   //�жϷ���λ
	
	int e = 0;
	for(int i = 1; i < 9; ++ i){        //����ָ��λ
		e = e * 2 + s[i] - '0';
	}
	e -= 127;
	
	int zs = 1;                    //��ΪIEEE��׼�ƻ�ȥ����λ��1�����������ʼֵ����Ϊ1
	float xs = 0.0, ans = 0.0;     //zs��������xs��С����ans���
	
	for(int i = 9; i < 9 + e; ++ i){    //��������
		zs = zs * 2 + s[i] - '0';
	}
	
	double w = 0.5;                     //ע�ⲻҪ��int
	for(int i = 9 + e; i < n; ++ i){    //С������
		xs += (s[i] - '0') * w;  
		w /= 2;
		
	}
	
	ans = zs + xs;
	
	printf("%f", ans);
	
	return 0;
}
