#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int vis[100005]={0};
int stack[100005]={0};
int po=0;
int n;
int cost[100005];
int push(int a)
{
	po++;
	stack[po]=a;
	return 0;
}
int pop()
{
	po--;
	return 0;
}
typedef struct Node
{
	int point;
	struct Node *next;
}node;
node * arr[100005];
node * tra[100005];
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
int dfs(int u)
{
	node * p;
	p=arr[u]->next;
	vis[u]=1;
	while(p!=NULL)
	{
		if(vis[p->point] == 0)
			dfs(p->point);
		p=p->next;
	}
	push(u);
	return 0;
}
int count=0;
int min=100000000;
int dfs_rev(int u)
{
	node *p;
	p=tra[u]->next;
	vis[u]=1;
	if(cost[u]<min)
	{
		min=cost[u];
		count=1;
	}
	else if(cost[u]==min)
	{
		count++;
	}
	while(p!=NULL)
	{
		if(vis[p->point]==0)
		{
			dfs_rev(p->point);
		}
		p=p->next;
	}
	return min;
}
int main()
{
	int t,i,m,x,y,j;
	scanf("%d",&t);
	while(t!=0)
	{
		po=0; //added at last
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->next=NULL;
			arr[i]=temp;
			node *temp1=(node *)malloc(sizeof(node));
			temp1->next=NULL;
			tra[i]=temp1;
		}
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y); 
			node *temp=(node *)malloc(sizeof(node));
			temp->point=y;
			temp->next=arr[x]->next;
			arr[x]->next=temp;
			//link(arr[x],y);
			temp=(node *)malloc(sizeof(node));
			temp->point=x;
			temp->next=tra[y]->next;
			tra[y]->next=temp;
			//link(tra[y],x);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]!=1)
				dfs(i);
		}
		for(i=1;i<=n;i++)
			vis[i]=0;
		int ans=0,way=1;
		count=0;
		while(po!=0)
		{
			int q= stack[po];
			pop();	
			if(vis[q]==0)
			{
				count=0;
				min=INT_MAX;
				int cost=dfs_rev(q);
				ans=ans+cost;
				way=((way)*(count%1000000007))%1000000007;
			}
		}
		printf("%d %d\n",ans,way);
		t--;
	}
	return 0;
}
