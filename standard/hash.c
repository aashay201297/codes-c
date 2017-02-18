#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	        int point;
		        struct Node *next;
}node;

node * arr[11];
int print(node * head,int num)
{
	printf("%d-> ",num);
	if(head->next==NULL)
	{
		printf("\n");
		return 0;
	}
	head=head->next;
	while(head->next!=NULL)
	{
		printf("%d ",head->point);
		head=head->next;
	}
	printf("%d",head->point);
	printf("\n");
}
int link(node *head,int num)
{
	node * pointer=head;
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}                
	node *temp=(node *)malloc(sizeof(node));
	temp->point=num;
	pointer->next=temp;
	temp->next=NULL;
	return 0;
}
int insert(int a)
{
	int temp=a%10,i;
	link(arr[temp],a);
	for(i=0;i<10;i++)
		print(arr[i],i);
	return 0;
}
int search(int a)
{
	int temp=a%10;
	node *p=arr[temp];
	node *p1=NULL;
	int flag=0,i;
	while(p->point!=a)
	{
		if(p->next==NULL)
		{
			flag=1;
			break;
		}
		p1=p;
		p=p->next;	
	}
	if(flag==1)
		printf("element not found\n");
	else
		printf("found\n");
	//for(i=0;i<10;i++)
	//	print(arr[i],i);
}
int delete(int a)
{
	int temp=a%10,i;
	node *p=arr[temp];
	node *p1=NULL;
	int flag=0;
	while(p->point!=a)
	{
		if(p->next==NULL)
		{
			flag=1;
			break;
		}
		p1=p;
		p=p->next;
	}
	if(flag==1)
		printf("this element doesn't exist\n");
	else 
	{
		p1->next=p->next;		
		free(p);
	}
	for(i=0;i<10;i++)
		print(arr[i],i);
}

int main()
{
	int n,i,a;
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		arr[i]=temp;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		int temp=a%10;
		link(arr[temp],a);
	}
	for(i=0;i<10;i++)
		print(arr[i],i);
	insert(3);
	insert(55);
	search(33);
	//search(1);

}
