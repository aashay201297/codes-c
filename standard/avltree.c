#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	int height;
	struct Node * left;
	struct Node * right;
}node;
int print(node *point)
{
	if(point==NULL)
		return 0;
	print(point->left);
	printf("%d,%d ",point->data,point->height);
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
int max(int a, int b)
{
	int r= (a>b?a:b);
	return r;
}
int update(node *p)
{
	int hl= (p->left==NULL?0:p->left->height);
	int hr= (p->right==NULL?0:p->right->height);
	return max(hl,hr)+1;
}
node *rotate_left(node *pt)
{
	node *r=pt->right;
	node *rl=r->left;
	pt->right=r->left;
	r->left=pt;
	pt->height=update(pt);
	r->height=update(r);
	return r;
}
node *rotate_right(node *pt)
{
	node *l=pt->left;
	node *lr=pt->left->right;
	pt->left=l->right;	
	pt->left->right=pt;
	pt->height=update(pt);
	l->height=update(l);
	return l;
}
node * balance(node *pt)
{
	int hl,hr;
	hl= (pt->left==NULL?0:pt->left->height);
	hr= (pt->right==NULL?0:pt->right->height);
	printf("hl=%d hr=%d\n",hl,hr);
	if(hl-hr<=1 && hl-hr>=-1)
	{
		printf("balanced\n");
		return pt;
	}
	if(hl>hr)
	{
		int hll,hlr;
		hll= (pt->left->left==NULL?0:pt->left->left->height);
		hlr= (pt->left->right==NULL?0:pt->left->right->height);
		if(hll<hlr)
			pt->left=rotate_left(pt->left);
		pt=rotate_right(pt);
		return pt;
	}
	else if(hl<hr)
	{
		int hrl,hrr;
		hrl = (pt->right->left==NULL?0:pt->right->left->height);
		hrr = (pt->right->right==NULL?0:pt->right->right->height);
		if(hrr<hrl)
			pt->right=rotate_right(pt->right);
		pt=rotate_left(pt);
	}
}
node *insert(node * point,int x)
{
	/*if(point->left !=NULL && x<point->data)
	  {
	  point = insert(point->left,x);
	  }
	  else if(point->right!=NULL && x>= point->data)
	  {
	  point = insert(point->right,x);
	  }
	  else if(point->right==NULL || point->left==NULL)
	  {
	  node *temp=(node *)malloc(sizeof(node));
	  temp->data=x;
	  temp->left=NULL;
	  temp->right=NULL;
	  temp->height=1;
	  return temp;
	  }
	  printf("balancing\n");
	  point=balance(point);*/
	if(point==NULL)
	{
		node *p;
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->height=1;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	if(x <= point->data)
	{
	  	printf("inserting %d at left\n",x);
		point->left=insert(point->left,x);
	}
	else 
	{
	  	printf("inserting %d at right\n",x );
		point->right=insert(point->right,x);
	}
	point=balance(point);
	return point;
}
int main()
{
	int n;
	printf("number of node:\n");
	scanf("%d",&n);
	node *head=(node *)malloc(sizeof(node));
	int i,x;
	//printf("scan\n");
	head->left=NULL;
	head->right=NULL;
	scanf("%d",&x);
	head->data=x;
	head->height=1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&x);
		insert(head,x);
	}
	printf("inorder:\n");
	print(head);
	/*printf("\npost order:\n");
	  printpost(head);
	  printf("\npreorder:\n");
	  printpre(head);
	  printf("\n");*/
}
