#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
	typedef struct node{
	ElemType data;
	struct node *next;	
	}Node,*LinkList;
//����������(ͷ�巨)
void CreatListhead(LinkList *L,int n) //���е�*L���ڶ���ָ�룬�������Ըı�ָ��ָ�����ݣ�Ҳ���Ըı�ָ�뱾������
{
	LinkList p;
	int i,o;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		printf("�������%d������",i+1);
		scanf("%d",&o);
		p->data=o;
		p->next=(*L)->next;
		(*L)->next=p;
	 } 
} 
//����������β�壩
 void CreatListheadTail(LinkList *L,int n)
 {
	LinkList p,q;
	int i,o;
	*L=(LinkList)malloc(sizeof(Node));
//	q=NULL;
	q=(*L);//��q�̳У�*L����ʹ������ͷ���󲻶����ӽڵ㣬����*L��������ԭʼλ�� 
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		printf("�������%d������",i+1);
		scanf("%d",&o);
		p->data=o;
		q->next=p;
		q=p;
	}
	q->next=NULL;
 }
 //����
 int ListInsert(LinkList *L,int i,ElemType e) //iΪ����λ�ã�eΪ����data 
 {
 	int j;
 	LinkList p,q;
 	p=(*L)->next;
 	for(j=1;j<i;j++)
 	{
 		p=p->next;
	 }
	 q=(LinkList)malloc(sizeof(Node));
	 q->data=e;
    q->next=p->next;
    p->next=q;
	
 }
 //ɾ��
 int ListDelite(LinkList *L,int i) 
 {
 	int j;
 	LinkList p,q,s;
 	p=(*L)->next;
 	for(j=2;j<i;j++)
 	{
 		p=p->next;
	}
	q=p->next;
	p->next=p->next->next;
	free(q);
 }
//����
void GetAllElem(LinkList L)
{
	int i;
	LinkList p;
	p=L->next;
	while(p)
	{
	  printf("%d\n",p->data);
	  p=p->next;
	}
 } 
int main(){
		LinkList L=NULL;
		int n;
		printf("���������");
		scanf("%d",&n);
		CreatListheadTail(&L,n);
		ListInsert(&L,1,99);
		ListDelite(&L,2) ;
	    GetAllElem(L);0
	
}
