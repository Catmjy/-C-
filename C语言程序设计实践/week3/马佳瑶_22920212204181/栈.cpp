#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100    //ջ��ʼ��С
#define STACKINCREMENT 10    //ջ��������
#define OK 1              //ջ�������ش���
#define ERROR 0
#define OVERFLOW -2

typedef  int SElemType; //ջ��Ԫ������Ϊ����
typedef  int Status;
//ջ��������ֵΪһ������ֵ��ʾ��״̬


typedef struct {                 //ջָ��ṹ�嶨��
	SElemType * base;         //ջ��ָ��
	SElemType * top;           //ջ��ָ��
	int stacksize;                   //��ǰ�ѷ���ռ���
} SqStack;                          //������

Status InitStack(SqStack *sp) {
	//������ָ���ջָ��ṹ���ָ��
	sp->base =  (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));                                //����ջ�ռ䣬��ջ��ָ��

	if (!sp->base) exit(OVERFLOW);
	//����ʧ����ָ��Ϊ��(0)��������
	sp->top = sp->base;              //��ջ��ָ�����ջ��ָ��
	sp->stacksize = STACK_INIT_SIZE;                 //��ջ��Сֵ

	return OK;
}

Status Push(SqStack *sp,SElemType data) {
	//2��������1��SqStackָ�룬2��Ҫѹ�����
	if (sp->top - sp->base >= sp->stacksize)
		//��ջ��׷�Ӵ洢�ռ�
	{
		sp->base = (SElemType *)realloc(sp->base, (sp->stacksize + STACKINCREMENT)*sizeof(SElemType));

		if (!sp->base) exit(OVERFLOW);
		sp->top = sp->base + sp->stacksize;       //����ջ��ָ��
		sp->stacksize += STACKINCREMENT; //�޸�ջ��Сֵ
	}                                        //*(sp->top)=data; (sp->top)++;
	*sp->top++ = data;    //������ջ��ջ��ָ����1
	return OK;
}

Status Pop(SqStack *sp, SElemType *data)
//2��������1��SqStackָ�룬2�ǳ�ջ����ŵĵ�ַ
{
	if (sp->top == sp->base)
		return ERROR;     //��ջ�գ�����
	*data = *(--sp->top);//ջ��ָ���ȼ�1��ջ��Ԫ�س�ջ��
	//(sp->top)--,*data=*(sp->top)
	return OK;
}

Status StackEmpty(SqStack *sp) {
	return sp->top == sp->base;
}                                      //���򷵻�1�������򷵻�0


int main() {

}
