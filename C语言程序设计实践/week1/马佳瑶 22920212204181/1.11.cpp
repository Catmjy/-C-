#include<stdio.h>
#include<string.h>


int uniquePaths(int m, int n) {
  //���亯��������·����
  
  if(m == 1 || n == 1) return 1;
  return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}
int main(){
	int m=3,n=2;
	int k=uniquePaths(m,n);
	printf("����%d��·��",k);
	return 0;
}
