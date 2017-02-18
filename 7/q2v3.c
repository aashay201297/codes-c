#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long n;
//long long m=1000000007;
typedef struct Node
{
	long long point;
	long long val;
	struct Node *next;
}node;
node * arr[1000005];
//long long int x=1;
void fun(node * p)
{
	long long x=1;
	//printf("vallong for %lld value =%lld\n",p->point,p->val);
	long long i,temp;
	node * head=p;
	p=p->next;
	while(p!=NULL)
	{
		if(arr[p->point]->val==INT_MIN)
		{
			fun(arr[p->point]);
		}
		x=((x)*((arr[p->point]->val+1)%1000000007))%1000000007;
		p=p->next;
	}
	head->val=x%1000000007;
}
int main()
{
	long long t,i,x,y,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->next=NULL;
			temp->val=INT_MIN;
			arr[i]=temp;
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%lld %lld",&x,&y); 
			node *temp=(node *)malloc(sizeof(node));
			temp->point=y;
			temp->next=arr[x]->next;
			arr[x]->point=x;
			arr[x]->next=temp;
		}
		for(i=1;i<=n;i++)
		{
			if(arr[i]->next ==NULL)
				arr[i]->val=1;
		}
		/*for(i=1;i<=n;i++)
		{
			int temp=1;
			if(arr[i]->val!=1)
			{
				//x=1;
				fun(arr[i]);
				node * q= arr[i]->next;
				while(q!=NULL)
				{
					temp=((temp)*((arr[q->point]->val+1)%1000000007))%1000000007;
					q=q->next;
				}
			}
		}*/
		x=1;
		fun(arr[1]);
		//printf("i m here\n");
		/*node * p =arr[1]->next;
		long long x=1;
		while(p!=NULL)
		{
			x=((x)*((arr[p->point]->val+1)%1000000007))%1000000007;
			p=p->next;
		}
		arr[1]->val=x%1000000007;*/
		/*for(i=1;i<=n;i++)
		{
			int temp=1;
			if(arr[i]->val!=1)
			{
				node * p=arr[i]->next;
				while(p!=NULL)
				{
					temp=((temp)*((arr[i]->val+1)%1000000007))%1000000007;		
					p=p->next;
				}
			}
			arr[i]->val=temp;
		}*/
		long long ans=0;
		//for(i=1;i<=n;i++)
		//	printf("val=%lld\n",arr[i]->val);
		for(i=1;i<=n;i++)
		{

			ans=ans+(arr[i]->val)%1000000007;
			ans=ans%1000000007;
		}
		printf("%lld\n",ans%1000000007);
	}
	return 0;
}
