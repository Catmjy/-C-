#include<stdio.h>
#include<string.h>

//����һ������ m x n ��Ԫ�صľ���m ��, n �У����밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ�ء�

int res[100];  //����ȫ�ֱ�������� 

int *spiralOrder(int* matrix, int matrixRowSize, int matrixColSize)
{

    int c1 = 0, r1 = 0, rh = matrixRowSize - 1, ch = matrixColSize - 1, count = 0;
 
    while(1)
    {
        for(int j = c1; j <= ch; ++ j) res[count ++] = *(matrix + c1 * matrixColSize + j);
        if(++ r1 > rh) break;
        for(int i = r1; i <= rh; ++ i) res[count ++] = *(matrix + i * matrixColSize + ch);
        if(-- ch < c1) break;
        for(int j = ch; j >= c1; -- j) res[count ++] = *(matrix + rh * matrixColSize + j);
        if(-- rh < r1) break;
        for(int i = rh; i >= r1; -- i) res[count ++] = *(matrix + i * matrixColSize + c1);
        if(++ c1 > ch) break;
        
    }
//  for(int i = 0; i < 9; ++ i) printf("%d ", res[i]);
//  puts("");
    return res;
} 
int main(){
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int matrixRowSize=3,matrixColSize=3;
	int *returnnum=spiralOrder(a[0], matrixRowSize, matrixColSize);
	int *p;
	for(p=returnnum;p<returnnum+9;p++) 
    { 
		printf("%4d",*p); 
     } 
	return 0;
}
