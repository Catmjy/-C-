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

int day_cnt, night_cnt, idx;
FILE *fp;

int main() {
	Pointer Head=NULL;
	int i;
	if((fp = fopen("d:\\Order.bin", "w+")) == NULL) {
		puts("can not open file!");
	}
	do {
		printf("\n1����������(Insert)\n");
		printf("2��������ѯ(Serch)\n");
		printf("3�������޸�(Update)\n");
		printf("4������ɾ��(Delete)\n");
		printf("5��������ʾ(Show)\n");
		printf("6�������˳�(Exit)\n");
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
				printf("����ѡ������ѡ");
				break;
		}
	} while(i!=6);

	int n = day_cnt + night_cnt;
	if((fwrite(Head, sizeof(GuestLink), n, fp)) != n) {
		puts("Can not write file!");
	}
	fclose(fp);                                         //6���˳�
	return 0;

}

//������������������ԣ�
void  Insert(Pointer *Head) {
	Pointer p,q,r;

	p=q=*Head;
	while(p!=NULL) {                          //���ң��ߵ���β
		if( p->number==idx + 1) {
			printf("������ͬ��ţ�");    //���У�������
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

	if(day_cnt >= MaxSize && night_cnt >= MaxSize) {
		puts("��Ǹ��ԤԼ��������");
		return;
	} else {
		++ idx;
		printf("��ǰ���Ϊ��%d\n", idx);
		r->number=idx;

		printf("������������");
		scanf("%s", r->name);       //������Ϣ
		printf("������������");
		scanf("%d", &r->sum);
		printf("�������ò�ʱ�䣺");
		scanf("%s",r->time);          //Ӧ�������������

		if(strcmp(r->time, "18��") < 0) {
			if(day_cnt + 1 > MaxSize) {
				printf("��ʱ�������������Լʱ��\n");
				while(scanf("%s", r->time), strcmp(r->time, "18��") < 0) {
					printf("��ʱ�������������Լʱ��\n");
				}
			} else ++ day_cnt;
		} else {
			if(night_cnt + 1 > MaxSize) {
				printf("��ʱ�������������Լʱ��\n");
				while(scanf("%s", r->time), strcmp(r->time, "18��") >= 0) {
					printf("��ʱ�������������Լʱ��\n");
				}
			} else ++ night_cnt;
		}
	}
}


void Search(Pointer Head) {
	int flag=1;
	char name[30];
	Pointer p=Head;
	printf("������Ҫ��ѯ��������\n");
	scanf("%s", name);                            //������
	while( p!=NULL && flag ) {
		if(strcmp(name, p->name) == 0) {                  //������ʾ
			printf("������%s\n", p->name);

			printf("������%d\n", p->sum);
			printf("ʱ���ǣ�%s\n", p->time);
			flag=0;
		}              //flag�ɲ���ʡ��
		else   p=p->next;           //������ָ����һ���
	}
	if( flag )      printf("û�в�ѯ������\n");             //�����þͶ��ˣ�
}


//Ӧ������ʾ���޸�
void Update(Pointer Head) {
	int flag=1;
	char name[30];
	Pointer p=Head;
	printf("\n������������");
	scanf("%s", name);                          //������
	while( p!=NULL && flag ) {
		if(strcmp(p->time, "18��") < 0) --day_cnt;
		else -- night_cnt;
		if( strcmp(name, p->name) == 0 ) {               //�����޸�
			puts("ԭ����Ϊ��");
			printf("������%s\n", p->name);
			printf("������%d\n", p->sum);
			printf("ʱ���ǣ�%s\n", p->time);

			puts("\n�������µ����ݣ�");
			scanf("%s", p->name);
			scanf("%d", &p->sum);                    //����©&
			scanf("%s", p->time);
			flag=0;
			if(strcmp(p->time, "18��") < 0) ++ day_cnt;
			else ++ night_cnt;
		}                  //flag�ɲ���ʡ��
		else   p=p->next;           //������ָ����һ���
	}
	if(flag)    printf("û���ҵ�Ҫ�޸ĵļ�¼����");
}

//ȱ�㣺ɾ����ʱ�䳤��
void Delete(Pointer *Head) {
	int flag=1;
	char name[30];
	Pointer p,q;
	printf("\n������������");
	scanf("%s", name);                                    //������
	p=q=*Head;
	while( p!=NULL && flag ) {
		if( strcmp(name, p->name) == 0) {  //����ɾ��
			flag=0;
			puts("��Ҫɾ��������Ϊ��");
			printf("������%s\n", p->name);
			printf("������%d\n", p->sum);
			printf("ʱ���ǣ�%s\n", p->time);
			puts("��1����ɾ������0����ɾ����");
			int k;
			scanf("%d", &k);
			if(k == 0) break;

			if(p==*Head) {
				*Head=p->next;
				free(p);
			} else              {
				q->next=p->next;
				free(p);
			}
			if(strcmp(p->time, "18��") < 0) --day_cnt;
			else -- night_cnt;

		}          //flag�ɲ���ʡ��
		else  {
			q=p;    //qָ��ǰ,pָ����һ���
			p=p->next;
		}
	}
	if( flag )        printf("û���ҵ�����ɾ�������ݣ���");      //�����þͶ���
}


//������Ҫ��ҳ
void Show(Pointer Head) {
	Pointer p=Head;
	printf("\n");
	puts("\n���ԤԼ������\n");
	printf("        ���      ����       ����       ʱ��\n");
	while( p!=NULL ) {   //�б���ʾ
		if(strcmp(p->time, "18��") < 0) {  //����
			printf("%10d", p->number);
			printf("%12s", p->name);
			printf("%10d", p->sum);
			printf("%12s\n", p->time);
		}
		puts("");
		p=p->next;                //ָ����һ���
	}
	p=Head;
	puts("\n���ԤԼ������\n");
	printf("        ���      ����       ����       ʱ��\n");
	while( p!=NULL ) {   //�б���ʾ
		if(strcmp(p->time, "18��") >= 0) {  //���
			printf("%10d", p->number);
			printf("%12s", p->name);
			printf("%10d", p->sum);
			printf("%12s\n", p->time);
		}

		p=p->next;                //ָ����һ���
	}
}
