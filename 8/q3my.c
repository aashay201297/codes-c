#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long vis[500005]={0},level[500005]={0},flag[5000005]={0};
long long n,cost=0;
typedef struct Node
{
	long long point;
	long long level;
	struct Node *next;
}node;
long long q[500001],r=0,l=0,prime[500005];
//int flagp[1300005]={0};
long long flagp[5000005]={0};
long long push(long long n)
{
	q[r]=n;
	if(r==500000)
	{
		r=1;
		return 0;
	}
	r++;
	return 0;
}
long long pop()
{
	long long temp=q[l];
	if(l==500000)
	{
		l=1;
		return temp;
	}
	l++;
	return temp;
}
void sieve()
{
	long long p,i;
	for (p=2; p*p<=5000000; p++)
	{
		if (flagp[p] == 0)
		{
			for (i=p*2; i<=5000000; i += p)
				flagp[i] = 1;
		}
	}
	long long j=1;
	for (p=2; p<=5000000; p++)
	{
		if (flagp[p]==0)
		{
			prime[j]=p;
			//count++;
			j++;
		}
	}
}
node * arr[500005];
long long prob=0;
/*long long dfs(long long u)
{
	node * p;
	p=arr[u]->next;
	if(vis[u]==1)
	{
		flag=1;
		return 0;
	}
	if(vis[u]==0)
	{
		//printf("temporatay marking %lld\n",u);
		vis[u]=1;
	}
	while(p!=NULL)
	{
		if(vis[p->point] == 0 || vis[p->point]==1)
			dfs(p->point);
		p=p->next;
	}
	//printf("permanently marking %lld\n",u);
	vis[u]=2;
	return 0;
}*/
long long dfs(long long u)
{
	long long i;
	vis[u]=1;
	node *p=arr[u]->next;;
	while(p!=NULL)
	{
		if(flag[p->point]==1)
			prob=1;
		if(vis[p->point]==0)
		{
			if(flag[u]==0)
				flag[u]=1;
			else if(flag[p->point]==1)
				prob=1;
			dfs(p->point);
		}
		p=p->next;
	}
	flag[u]=2;
	return 0;
}
long long bfs()
{	
	while(l!=r)
	{
		long long top=pop();	
		node * p=arr[top]->next;
		while(p!=NULL)
		{
			//if(arr[top]->level+1> arr[p->point]->level)
			//{
			arr[p->point]->level=arr[top]->level+1;
			level[p->point]=arr[top]->level+1;
			//}
			push(p->point);
			p=p->next;
		}
	}
	return 0;
}
int main()
{
	long long t,i,m,x,y,j;
	scanf("%lld",&t);
	sieve();
	while(t--)
	{
		l=0;
		r=0;
		for(i=0;i<=n;i++)
		{
			flag[i]=0;
			vis[i]=0;
		}
		cost=0;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->next=NULL;
			temp->level=INT_MIN;
			temp->point=i;
			arr[i]=temp;
		}
		for(i=0;i<n;i++)
			level[i]=0;
		arr[0]->level=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld",&x,&y); 
			node *temp=(node *)malloc(sizeof(node));
			temp->point=x;
			temp->next=arr[y]->next;
			arr[y]->next=temp;
		}
		prob=0;
		for(i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				dfs(i);
			}
			if(prob==1)
			{
				break;
				//printf("evil emperor loses\n");
				//return 0;
			}
		}
		if(prob==1)
			printf("evil emperor loses\n");
		else
		{
			prob=0;
			push(0);
			bfs();
			for(i=0;i<n;i++)
			{
				if(level[i]<= 0 && i!=0)
				{
					prob=1;
					printf("evil emperor loses\n");
					break;
				}
				//printf("level of %d is %d and prime is %d\n",i,level[i],prime[level[i]]);
				if(level[i]>=0)
					cost+=prime[level[i]];
			}
			if(prob!=1)
				printf("%lld\n",cost);
		}

	}
	return 0;
}
