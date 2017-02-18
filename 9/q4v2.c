#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node
{
	long long point;
	long long cost;
	//long long present;
	struct Node *next;
}node;
node arr[100005];
node *rev[100005];
int flag,size,present[100005],n,i;
int findmin()
{
		/*	printf("\n");
			printf("cost =\n");
			for(i=1;i<=n;i++)
				printf("%lld ",arr[i].cost);
			printf("\n\n");
			printf("present array:\n");
			for(i=1;i<=n;i++)
				printf("%d ",present[i]);
			printf("\n\n");*/
	flag=0;
	int mincost=INT_MAX;
	int min;
	for(i=1;i<=n;i++)
	{
		if(arr[i].cost != INT_MAX && present[i]==1)
		{
			//printf("not INT_MAX present\n");
			flag=1;
		}
		if(arr[i].cost< mincost && present[i]==1)
		{
			mincost=arr[i].cost;
			min=i;
		}
	}
	return min;
}
int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int func(long long min)
{	
	node *p=rev[min]->next;
	while(p!=NULL)
	{
		int temp_c=max(p->cost,arr[min].cost);
		if(temp_c < arr[p->point].cost )
		{
			arr[p->point].cost=temp_c;
		}
		p=p->next;
	}
	//printf("%d not present\n",min);
	present[min]=0;
	size--;
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long j,m,s,d,x,y,c;
		scanf("%lld %lld",&n,&m);
		size=n;
		for(i=0;i<=n;i++)
			present[i]=1;
		for(i=0;i<=n;i++)
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->next=NULL;
			temp->cost=0;
			temp->point=i;
			rev[i]=temp;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld %lld",&x,&y,&c); 
			node *temp=(node *)malloc(sizeof(node));
			temp->point=y;
			temp->cost=c;
			temp->next=rev[x]->next;
			rev[x]->next=temp;
		}
		scanf("%lld %lld",&s,&d);
		//printf("s and d scanned\n");
		for(i=1;i<=n;i++)
		{
			arr[i].point=i;
			arr[i].cost=INT_MAX;
			//arr[i]->present=1;
			//printf("initialse\n");
		}
		//printf("done\n");
		arr[s].cost=0;
		while(size!=0)
		{
			//printf("******************************************************************`\n");
			int min=findmin();
			//printf("min=%lld\n",min);
			if(flag==0)
			{
				//printf("flag = 0\n");
				break;
			}
			else  
			{
				if(present[min]==1)
					func(min);
			}
			//printf("******************************************************************`\n");
		}
		/*printf("present array:\n");
		for(i=1;i<=n;i++)
			printf("%d ",present[i]);
		printf("\n");*/
		if(flag==0)
			printf("NO PATH\n");
		else 
			printf("%lld\n",arr[d].cost);
	}
	return 0;
}
