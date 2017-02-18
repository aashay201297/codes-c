#include<stdio.h>
#include<stdlib.h>
//int g[100][100]={0};
int vis[200005]={0};
int n;
//int num=1;
int order[200005][2];
typedef struct Node
{
	int point;
	long long int val;
	struct Node *next;
}node;
node * arr[200005];
int final=0;
int dfs(int u)
{
	node *p;
	vis[u]=1;
	p=arr[u]->next;
	//printf("%d ",u+1);
	if(p==NULL)
	{
		printf("h\n");
		arr[p->point]->val=1;
		return 0;
	}
	while(p!=NULL)
	{	
		if(!vis[p->point])
			dfs(p->point);
		p=p->next;
	}
	p=arr[u]->next;
	int count=0;
	while(p!=NULL)
	{
		count+=arr[p->point]->val;
		p=p->next;
	}
	arr[u]->val=count+1;
	return 0;
}
int main()
{
	int i,m,x,y,j,l,t;
	scanf("%d",&t);
	while(t--)
	{
		final=0;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			vis[i]=0;
		for(i=1;i<=n;i++)
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->next=NULL;
			temp->point=i;
			arr[i]=temp;
			temp->val=0;
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&x,&y); 
			order[i][1]=x;
			order[i][2]=y;
			node *temp=(node *)malloc(sizeof(node));
			temp->next=arr[x]->next;
			temp->point=y;
			arr[x]->next=temp;
			temp=(node *)malloc(sizeof(node));
			temp->next=arr[y]->next;
			temp->point=x;
			arr[y]->next=temp;
		}
		dfs(1);
		for(i=1;i<=n;i++)
		{
			printf("%d-> ",i);
			node *p=arr[i]->next;
			while(p!=NULL)
			{
				printf("%d ",p->point);
				p=p->next;
			}
			printf("\n");
		}	
		//
		for(i=1;i<=n-1;i++)
		{
			int l=order[i][1];
			int r=order[i][2];
			long long int first=arr[l]->val;
			long long int sec=arr[r]->val;
			if(first>sec)
			{
				long long int s1=sec;
				long long int s2=n-sec;
				printf("%lld ",s1*s2);
			}
			else
			{
				int s1=first;
				int s2=n-first;
				printf("%lld ",s1*s2);
			}

		}
		printf("\n");
	}
	return 0;
}
