#include<stdio.h>
#define MaxSize 20

struct guest_info {
	char  name[8];     //����
	int     sum;             //����
	char  time[10];     //ʱ��
	int     number;       //���
} GuestList[MaxSize];


void Insert( int * );   //����
void Search( int );    //��ѯ
void Update( int );   //�޸�
void Delete( int * ); //ɾ��
void Show( int );      //��ʾ

int main() {
	int i,  count=0;
	do {             //��ʾ��ʾ��Ϣ,��1...5,6�˳�����
		scanf("%d", &i);                          //���빦��ѡ��
		switch(i) {
			case 1:
				Insert( &count );
				break;
			case 2:
				Search( count );
				break;
			case 3:
				Update( count );
				break;
			case 4:
				Delete( &count );
				break;
			case 5:
				Show( count );
				break;
			case 6:
				break;
			default:
				printf("������ѡ");
				break;
		}
	} while( i!=6 );               //6���˳�
	return 0;
}

void Insert(int *count) {
	int i, in_number;
	if(*count==MaxSize) {
		printf("��");    //��������
		return;
	}
	scanf("%d", &in_number);                            //���������
	for( i=0; i<*count; i++ )
		if(GuestList[i].number==in_number) {    //���д˱��
			printf("������ͬ���");    //������
			return;
		}
	GuestList[i].number=in_number;          //i����ָ���β
	scanf("%s", GuestList[i].name);
	scanf("%d", &GuestList[i].sum);
	scanf("%s", GuestList[i].time);
	(*count)++;                                   //��������1
}

void Search(int count) {
	int i,  number,  flag=1;
	printf("��������");
	scanf("%d",&number);                            //������
	for(i=0; i<count && flag; i++) {
		if(GuestList[i].number==number) {    //������ʾ
			printf("������%s", GuestList[i].name);
			printf("������%d", GuestList[i].sum);
			printf("ʱ���ǣ�%s", GuestList[i].time);
			flag=0;
		}                //flag��ʡ
		else                                 //����д��û���⣿
			printf("û�в�ѯ������");             //�������ʾ��
	}                                       //�����������д��
}

//Ӧ������ʾ���޸�
void Update(int count) {
	int i, number, flag=1;
	printf("��������");
	scanf("%d",&number);                            //������
	for(i=0; i<count && flag; i++) {
		if(GuestList[i].number==number) {    //�����޸�
			scanf("%s", GuestList[i].name);        //����©
			scanf("%d", &GuestList[i].sum);
			scanf("%s", GuestList[i].time);
			flag=0;
		}           //flag��ʡ
		else                               //����д��û���⣿
			printf("û�в�ѯ������ɾ�������ݣ���");
	}
}

//ȱ�㣺ɾ����ʱ�䳤��
void Delete(int *count) {
	int i, j, number, flag=1;
	printf("��������");
	scanf("%d",&number);                                    //������
	for(i=0; i<*count && flag; i++) {
		if(GuestList[i].number==number) {           //����ɾ��
			for(j=i; j<*count-1; j++)             //��һԪ����ǰ�ƶ�
				GuestList[j]=GuestList[j+1];
			flag=0;                //flag��ʡ
			(*count)--;
		} else                                //����д��û���⣿
			printf("û....");
	}
}

//������Ҫ��ҳ
void Show(int  count) {
	int i;
	printf("\n");
	printf("���   ����   ����  ʱ��");
	for(i=0; i<count; i++) {                    //�б���ʾ
		printf("%10d", GuestList[i].number);
		printf("%12s", GuestList[i].name);
		printf("%10d", GuestList[i].sum);
		printf("%12s\n", GuestList[i].time);
	}
}






