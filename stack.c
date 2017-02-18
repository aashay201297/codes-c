#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;
Node *start;
int pop()
{
	Node *temp=start;
	start=start->next;	
	free(temp);
	print(start);
	return 0;
}
int push(int num)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=num;
	temp->next=start;
	start=temp;
	print(start);
	return 0;
}
int print(Node *head)
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n-------------------------\n");
	return 0;
}
int main()
{
	
	Node *head = NULL;
	int i,n;
	unsigned int_size = sizeof(int);
	printf("write number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		Node *temp= (Node*)malloc(sizeof(Node));
		scanf("%d",&temp->data);
		temp->next= head;
		head=temp;
	}
	start=head;
	printf("what do you wanna do?\n");
	printf("1 for push\n2for pop\n");
	int x,l;
	scanf("%d",&x);
	switch(x)
	{
		case 1:printf("write value:\n");
		       scanf("%d",&l);
		       push(l);
		       printf(start);
		       break;
		case 2:pop();
		       printf(start);
		       break;
	}
	return 0;
}
