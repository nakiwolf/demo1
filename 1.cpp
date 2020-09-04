#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
	typedef struct node{
	ElemType data;
	struct node *next;	
	}Node,*LinkList;
//创建单链表(头插法)
void CreatListhead(LinkList *L,int n) //其中的*L属于二级指针，不仅可以改变指针指向内容，也可以改变指针本身内容
{
	LinkList p;
	int i,o;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		printf("请输入第%d个数字",i+1);
		scanf("%d",&o);
		p->data=o;
		p->next=(*L)->next;
		(*L)->next=p;
	 } 
} 
//创建单链表（尾插）
 void CreatListheadTail(LinkList *L,int n)
 {
	LinkList p,q;
	int i,o;
	*L=(LinkList)malloc(sizeof(Node));
//	q=NULL;
	q=(*L);//由q继承（*L）的使命，在头结点后不断增加节点，而（*L）还处于原始位置 
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		printf("请输入第%d个数字",i+1);
		scanf("%d",&o);
		p->data=o;
		q->next=p;
		q=p;
	}
	q->next=NULL;
 }
 //插入
 int ListInsert(LinkList *L,int i,ElemType e) //i为插入位置，e为插入data 
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
 //删除
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
//遍历
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
		printf("请输入表长：");
		scanf("%d",&n);
		CreatListheadTail(&L,n);
		ListInsert(&L,1,99);
		ListDelite(&L,2) ;
	    GetAllElem(L);0
	
}
