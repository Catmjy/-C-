#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct guest_info {
	char  name[8];      //����
	int     sum;              //����
	char  time[10];      //ʱ��
	int     number;       //���
	struct guest_info *next;
} GuestLink, *Pointer;

void Insert (Pointer *Head );   //����
void Search( Pointer Head );    //��ѯ
void Update( Pointer Head );   //�޸�
void Delete( Pointer *Head ); //ɾ��
void Show( Pointer Head );      //��ʾ


int main() {
	Pointer Head=NULL;
	int i;
	do {     //��ʾ��ʾ��Ϣ,��1...5,6�˳�����
		scanf("%d", &i);                          //���빦��ѡ��
		switch(i) {
			case 1:
				Insert(&Head);
				break;
			case 2:
				Search(Head);
				break;
			case 3:
				Update(Head);
				break;
			case 4:
				Delete(&Head);
				break;
			case 5:
				Show(Head);
				break;
			case 6:
				break;
			default:
				printf("������ѡ");
				break;
		}
	} while(i!=6);                                           //6���˳�
	return 0;

}

//������������������ԣ�
void  Insert(Pointer *Head) {
	int in_number;
	Pointer p,q,r;
	scanf("%d", &in_number);                       //������
	p=q=*Head;
	while(p!=NULL) {                          //���ң��ߵ���β
		if( p->number==in_number) {
			printf("����");    //���У�������
			return;
		} else {
			q=p;    //qָ��ǰ��pָ����һ��
			p=p->next;
		}
	}
	r=( Pointer )malloc( sizeof( GuestLink ) );     //����ռ�
	r->next=NULL;                                     //���ö�βָ����
	if(r==NULL) {
		printf("����ռ�ʧ��");    //Ӧǰ��
		return;
	}
	if(q==NULL)                          //�ձ�
		*Head=r;                           //�ձ����½��Ϊͷ���
	else {
		q->next=r;    //��������β
	}
	r->number=in_number;
	scanf("%s", r->name);       //������Ϣ
	scanf("%d", &r->sum);
	scanf("%s",r->time);          //Ӧ�������������
}


void Search(Pointer Head) {
	int number, flag=1;
	Pointer p=Head;
	printf("��������");
	scanf("%d", &number);                            //������
	while( p!=NULL && flag ) {
		if(p->number==number) {                  //������ʾ
			printf("������%s", p->name);

			printf("������%d", p->sum);
			printf("ʱ���ǣ�%s", p->time);
			flag=0;
		}              //flag�ɲ���ʡ��
		else   p=p->next;           //������ָ����һ���
	}
	if( flag )      printf("û...");             //�����þͶ��ˣ�
}


//Ӧ������ʾ���޸�
void Update(Pointer Head) {
	int number, flag=1;
	Pointer p=Head;
	printf("��������");
	scanf("%d",  &number);                          //������
	while( p!=NULL && flag ) {
		if( p->number==number ) {               //�����޸�
			scanf("%s", p->name);
			scanf("%d", &p->sum);                    //����©&
			scanf("%s", p->time);
			flag=0;
		}                  //flag�ɲ���ʡ��
		else   p=p->next;           //������ָ����һ���
	}
	if(flag)    printf("û....");
}

//ȱ�㣺ɾ����ʱ�䳤��
void Delete(Pointer *Head) {
	int number, flag=1;
	Pointer p,q;
	printf("��������");
	scanf("%d", &number);                                    //������
	p=q=*Head;
	while( p!=NULL && flag ) {
		if( p->number==number) {                        //����ɾ��
			if(p==*Head) {
				*Head=p->next;
				free(p);
			} else              {
				q->next=p->next;
				free(p);
			}
			flag=0;
		}          //flag�ɲ���ʡ��
		else  {
			q=p;    //qָ��ǰ,pָ����һ���
			p=p->next;
		}
	}
	if( flag )        printf("û...");      //�����þͶ���
}


//������Ҫ��ҳ
void Show(Pointer Head) {
	Pointer p=Head;
	printf("\n");
	printf("���   ����       ����    ʱ��");
	while( p!=NULL ) {                                   //�б���ʾ
		printf("%10d", p->number);
		printf("%12s", p->name);
		printf("%10d", p->sum);
		printf("%12s\n", p->time);
		p=p->next;                //ָ����һ���
	}
}

