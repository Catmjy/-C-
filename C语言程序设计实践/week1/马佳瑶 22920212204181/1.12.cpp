#include<stdio.h>
#include<string.h>


int uniquePathsWithObstacles(int* obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize){
  //���亯��������·����
   int r = obstacleGridRowSize, c = obstacleGridColSize;
   int *b = obstacleGrid;
   if( *(b + (r - 1) * 3 + c - 1) == 1) return 0;
   if(r == 1 || c == 1) return 1;
   return uniquePathsWithObstacles(b, r - 1, c) + uniquePathsWithObstacles(b, r, c - 1); 
   
}
int main(){
	int a[3][3]={0,0,0,0,1,0,0,0,0};
	int k=uniquePathsWithObstacles(a[0],3,3);
	printf("����%d��·��",k);

	return 0;
}
