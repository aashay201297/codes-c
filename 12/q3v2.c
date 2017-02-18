#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//int g[100][100]={0};
int vis[200005]={0};
int n;
//int num=1;
int cost[200005];
typedef struct Node
{
	int point;
	int val;
	int level;
	struct Node *next;
}node;
node * arr[200005];
int final=0;
int dfs(int u)
{
	node *p;
	vis[u]=1;
	p=arr[u]->next;
	while(p!=NULL)
	{	
		if(!vis[p->point])
		{
			arr[p->point]->level=arr[u]->level + 1;
			dfs(p->point);
		}
		p=p->next;

	}
	if(cost[u]!=-1)
	{
		arr[u]->val=cost[u];
		//printf("val of %d changed to %d\n",u,arr[u]->val);
	}
	return 0;
}
int dfs2(int u)
{
	node *p;
	vis[u]=1;
	p=arr[u]->next;
	//printf("called for %d\n",u);
	int l=arr[u]->level;
	if(l%2==1)
	{
		//printf("level is %d\n",l);
		while(p!=NULL)
		{	
			if(vis[p->point]==0)
			{
				dfs2(p->point);
				//arr[p->point]->val=arr[u]->level + 1;
				//if(arr[p->point]->level>max)
				//	max=arr[p->point]->level;
			}
			p=p->next;

		}
		int max=INT_MIN;
		p=arr[u]->next;
		while(p!=NULL)
		{
			//printf("vis[%d]=%d\n",p->point,vis[p->point]);
			if(arr[p->point]->val>max && vis[p->point]==2)
			{
				max=arr[p->point]->val;
				//printf("MAX changed to %d\n",arr[p->point]->val);
			}
			p=p->next;
		}
		if(max!=INT_MIN)
			arr[u]->val=max;
	}
	if(l%2==0)
	{
		//printf("level is %d\n",l);
		while(p!=NULL)
		{	
			if(vis[p->point]==0)
			{
				dfs2(p->point);
				//arr[p->point]->val=arr[u]->level + 1;
				//if(arr[p->point]->level<min)
				//	min=arr[p->point]->level;
			}
			p=p->next;

		}
		int min=INT_MAX;
		p=arr[u]->next;
		while(p!=NULL)
		{
			//printf("vis[%d]=%d val=%d\n",p->point,vis[p->point],arr[p->point]->val);
			if(arr[p->point]->val<min && vis[p->point]==2)
			{
				min=arr[p->point]->val;
				//printf("MIN changed to %d\n",arr[p->point]->val);
			}
			p=p->next;
		}
		if(min!=INT_MAX)
			arr[u]->val=min;
	}
	vis[u]=2;
	//printf("done visiting %d\n",u);
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
			node *temp=(node *)malloc(sizeof(node));
			temp->next=arr[x]->next;
			temp->point=y;
			arr[x]->next=temp;
			/*temp=(node *)malloc(sizeof(node));
			  temp->next=arr[y]->next;
			  temp->point=x;
			  arr[y]->next=temp;*/
		}
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
		/*for(i=1;i<=n;i++)
		  printf("%d ",cost[i]);
		  printf("\n");*/
		/*for(i=1;i<=n;i++)
		{
			printf("%d-> ",i);
			node *p=arr[i]->next;
			while(p!=NULL)
			{
				printf("%d ",p->point);
				p=p->next;
			}
			printf("\n");
		}*/
		arr[1]->level=1;
		dfs(1);
		for(i=0;i<=n;i++)
			vis[i]=0;
		dfs2(1);
		/*for(i=1;i<=n;i++)
		{
			printf("%d-> %d,%d\n",i,arr[i]->level,arr[i]->val);
		}*/
		printf("%d\n",arr[1]->val);
	}
	return 0;
}
