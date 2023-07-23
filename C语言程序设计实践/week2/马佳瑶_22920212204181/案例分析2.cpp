#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define SIZE 5

typedef struct student {
	int number;                     //����������
	int score[3];   
	double total;                       //ƽʱ����ĩ������
} STUDENT;


typedef enum boolen {
	False, True          //�ж�����ɼ��Ƿ������
} FLAG;

int cmp(const void *a,const void *b)
{
     STUDENT *aa = (STUDENT *)a;
     STUDENT *bb = (STUDENT *)b;
     if(fabs(aa->total - bb->total) > 1e-6) return (((aa->total) > (bb->total)) > 1e-6 ? 1 : -1);
     return aa->number > bb->number;
}

int accept_data(STUDENT stu[], int grade[]);
void show_data(STUDENT stu[], int sum, int grade[]);

void draw(int grade[]);
void count(int *max, int *min, double *pass, double ave[], double f[], STUDENT stu[], int sum);
void show_data2(int max, int min, double pass, double ave[], double f[]);

int main() {
	FILE *fp1, *fp2;
	int sum, max, min;
	double pass = 0;
	int grade[11] = {0};           //10������ͳ��
	STUDENT stu[SIZE];
	double ave[SIZE], f[SIZE]; //��ƽ���ɼ�����׼����
	sum = accept_data(stu, grade);                     //����
	show_data(stu, sum, grade);                         //��ʾ
	draw(grade);                                            //��ֱ��ͼ
	count(&max, &min, &pass, ave, f, stu, sum); //ͳ��
	show_data2(max, min, pass, ave, f);            //��ʾ
	if((fp1 = fopen("d://STU.bin", "wb")) == NULL) printf("can not open file!\n");
	if(fwrite(stu, sizeof(STUDENT), SIZE, fp1) != SIZE) printf ("file write error\n");
	if((fp2 = fopen("d://STUdata.bin", "w")) == NULL) printf("can not open file!\n");
	for(int i = 0; i < 11; ++ i) fprintf(fp2, "%d", grade[i]);
	for(int i = 0; i < SIZE; ++ i){
		fprintf(fp2, "%.1f", ave[i]);
		fprintf(fp2, "%.1f", f[i]);
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

int accept_data(STUDENT stu[], int grade[]) {
	int i = 0, sum = 0, temp, a1, a2, a3;
	FLAG flag;
	printf("��������������ɼ�ʱʹ��ƽʱ�ɼ��ı�������������ʾ");
	scanf("%d%d%d", &a1, &a2, &a3);
	while (i < SIZE) {
		printf("\n������ѧ�ţ�");
		scanf("%d", &stu[i].number);
		if (stu[i].number == -1) {
			sum = i;
			break;
		}

		printf("\n������ѧ����ƽʱ�ɼ������гɼ�����ĩ�ɼ���");
		flag = True;
		while (flag == True) {
			scanf("%d%d%d", &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
			if (stu[i].score[0] <= 100 && stu[i].score[0] >= 0 && stu[i].score[1] <= 100 && stu[i].score[1] && stu[i].score[2] <= 100 && stu[i].score[2]>= 0)
				flag = False;
			else
				printf("\n\007�������ݣ����ٴ�����ѧ����ƽʱ�ɼ������гɼ�����ĩ�ɼ���");
		}
		stu[i].total = (1.0 * a1 / 100 * stu[i].score[0] + 1.0 * a2 / 100 * stu[i].score[1] + 1.0 * a3 / 100 * stu[i].score[2]);

		temp = (stu[i].score[2]) / 10;
		if (temp == 10)
			grade[10] ++;
		else
			grade[temp + 1] ++;

		++ i;
		sum = i;
	}
	return sum;
}
void show_data(STUDENT stu[], int sum, int grade[]) {
	int i, j;
    qsort(stu, SIZE, sizeof(STUDENT), cmp);
	for (i = 0; i < sum; i++) {
		printf("%4d", stu[i].number);
		for (j = 0; j < 3; j++) {
			printf("%4d", stu[i].score[j]);
		}
		printf("  %.1f", stu[i].total);
		printf("\n");
	}
	printf("\n�����ηֲ������");
	for (i = 1; i <= 10; i++) {
		printf(" %d", grade[i]);
	}
}
void count(int *max, int *min, double *pass, double ave[], double f[], STUDENT stu[], int sum) {
	int i, j, p_sum = 0;
	int total[3];
	*max = *min = stu[0].score[1];
	if (stu[0].score[1] >= 60)
		p_sum++;
	for (i = 1; i < sum; i++) {
		if ((stu[i].score[1]) > *max)
			*max = stu[i].score[1];
		if ((stu[i].score[1]) < *min)
			*min = stu[i].score[1];
		if (stu[i].score[1] >= 60)
			p_sum++;
	}
	*pass = (1.0 * p_sum / sum) * 100;
	for (i = 0; i <= 2; i++)
		total[i] = 0;
	for (j = 0; j < 3; j++) {
		for (i = 0; i < sum; i++) {
			total[j] = total[j] + stu[i].score[j];
		}
	}
	for (j = 0; j < 3; j++)
		ave[j] = total[j] / sum;
	for (j = 0; j < 3; j++) {
		f[j] = 0;
		for (i = 0; i < sum; i++) {
			double temp = stu[i].score[j] - ave[j];
			f[j] = f[j] + temp * temp;
		}
		f[j] = sqrt(fabs(f[j]) / sum);
	}
}
void show_data2(int max, int min, double pass, double ave[], double f[]) {
	int j;
	char str1[3][20] = {"ƽʱ�ɼ�ƽ����", "��ĩ�ɼ�ƽ����", "�����ɼ�ƽ����"};
	char str2[3][20] = {"ƽʱ�ɼ���׼��", "��ĩ�ɼ���׼��", "�����ɼ���׼��"};
	printf("\n������=%6.2f%%��߷�=%d��ͷ�=%d\n", pass,max,min);
	for (j = 0; j < 3; j++)
		printf("\n%s=%6.2f %s=%6.2f\n", str1[j], ave[j], str2[j], f[j]);

}
void draw(int grade[]) {
	int i, j, max, k, temp, x;
	char screen[22][44];
	printf("\n\nģ��ֱ��ͼ\n");
	max = 0;
	for (i = 0; i <= 10; i++)
		if (grade[i] > max)
			max = grade[i];
	for (i = 1; i <= 10; i++)
		grade[i] = (int)(20.0 * grade[i] / max + 0.5);
	for (i = 0; i <= 21; i++) {
		for (j = 0; j <= 41; j++)
			screen[i][j] = 0;
	}
	for(i=0; i<=41; i++)
		screen[21][i]='-';
	screen[21][41]='X';
	screen[0][0]='Y';
	for(i=1; i<=21; i++)
		screen[i][0]='|';
	k=1;
	for(x=1; x<=10; x++,k=k+4) {
		temp=grade[x];
		if(temp!=0) {
			for(i=1; i<=temp; i++) {
				for(j=1; j<=4; j++) {
					screen[20-i+1][j+k]='*';
				}
			}
		}
	}
	for(i=0; i<=21; i++) {
		for(j=0; j<=41; j++) {
			if(screen[i][j]!=0)
				printf("%c",screen[i][j]);
			else
				printf(" ");
		}
		printf("\n");

	}
	printf("0  10  20  30  40  50  60  70  80  90  100\n");
	getch();

}
