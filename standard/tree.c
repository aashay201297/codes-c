#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
}node;
int insert(node * point,int x)
{
	if(point->left !=NULL && x< point->data)
	{
		insert(point->left,x);
	}
	else if(point->right!=NULL && x>= point->data)
		insert(point->right,x);
	else if(point->left == NULL && x<point->data)
	{
		node *temp=(node *)malloc(sizeof(node));
		point->left=temp;
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		printf("inserting %d at left\n",x);
		return 0;
	}
	else if(point->right == NULL && x>=point->data)
	{
		node *temp=(node *)malloc(sizeof(node));
		point->right=temp;
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		printf("inserting %d at right\n",x );
		return 0;
	}
}
int print(node *point)
{
	if(point==NULL)
		return 0;
	print(point->left);
	printf("%d ",point->data);
	print(point->right);	
}
int printpost(node * point)
{
	if(point==NULL)
		return 0;
	print(point->left);
	print(point->right);
	printf("%d ",point->data);
}
int printpre(node *point)
{
	if(point==NULL)
		return 0;
	printf("%d ",point->data);
	print(point->left);
	print(point->right);
}
int main()
{
	int n;
	printf("number of node:\n");
	scanf("%d",&n);
	node *head=(node *)malloc(sizeof(node));
	int i,x;
	printf("scan\n");
	head->left=NULL;
	head->right=NULL;
	scanf("%d",&x);
	head->data=x;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&x);
		insert(head,x);
	}
	printf("inorder:\n");
	print(head);
	printf("\npost order:\n");
	printpost(head);
	printf("\npreorder:\n");
	printpre(head);
}
