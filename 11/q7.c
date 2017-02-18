#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long n;
typedef struct Node
{
	long long point;
	long long cost;
	struct Node *next;
}node;
node * arr[1000005];
long long c=0,sum,max=INT_MIN;
long long vis[1000005]={0};
int dfs(int u)
{
	node * p;
	p=arr[u]->next;
	int x;
	vis[u]=1;
	while(p!=NULL)
	{
		if(vis[p->point] == 0)
		{
			c+=p->cost;
			//printf("added for node %d to %d and c is %d\n",u,p->point,c);
			if( c>max)
			{
				max=c;
				//	printf("cost changed to %d\n",max);
			}
			dfs(p->point);
			c=c-p->cost;
			//printf("subtracted for %d to %d\n",u,p->point); 
		}
		p=p->next;
	}
}

int main()
{
	long long t,i,x,y,j;
	sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		temp->cost=0;
		temp->point=i;
		arr[i]=temp;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&c);
		sum+=c;
		node *temp=(node *)malloc(sizeof(node));
		temp->point=y;
		temp->cost=c;
		temp->next=arr[x]->next;
		arr[x]->next=temp;
		node *temp1=(node *)malloc(sizeof(node));
		temp1->point=x;
		temp1->cost=c;
		temp1->next=arr[y]->next;
		arr[y]->next=temp1;
	}
	c=0;
	dfs(1);
	sum+=sum;
	//printf("max=%d sum=%d\n",max,sum);
	printf("%d\n",sum-max);
	return 0;
}
