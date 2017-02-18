#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}node;
node *tail;
node *start;
int push(int num)
{
	node *temp=(node*)malloc(sizeof(node));
	tail->next=temp;
	temp->data=num;
	temp->next=NULL;
	tail=temp;
	print(start);
	return 0;
}
int pop()
{
	node *temp=start;
	start=start->next;
	free(temp);
	print(start);
	return 0;
}
int print(node *head)
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	while(head!=NULL)
	{
		printf("%d ->",head->data);
		head=head->next;
	}
	printf("NULL\n-------------------------\n");
	return 0;
}
int main()
{
	node *head=NULL;
	int i,n;
	unsigned int_size = sizeof(int);
	printf("write number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		node *temp= (node*)malloc(sizeof(node));
		scanf("%d",&temp->data);
		temp->next= head;
		head=temp;
	}
	start=head;
	tail=start;
	while(tail->next != NULL)
	{
		tail=tail->next;
	}
	
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
}

