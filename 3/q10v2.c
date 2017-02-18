#include<stdio.h>

int st[100005]={0},st_point=0;

void push(int n)
{
	st[st_point]=n;
	st_point++;
}

void pop()
{
	if(st_point!=0)
		st_point--;
}

int topest()
{
	return st[st_point-1];
}

int max(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,i,j;
		scanf("%d", &n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		int R[n], L[n];
		i=0;
		while(i<n)
		{
			R[i]=n;
			L[i]=-1;
			i++;
		}
		push(0);
		for(i=1;i<n;i++)
		{
			int next=topest();
			while(a[i]<a[next])
			{
				R[next]=i;
				pop();
				if(st_point==0)
				{
					push(i);
					break;
				}
				next=topest();
			}
			if(a[i]>=a[next])
				push(i);
		}
		st_point=0;
		push(n-1);
		for(i=n-2;i>=0;i--)
		{
			int prev =topest();
			while(a[i]<a[prev])
			{
				L[prev]=i;
				pop();
				if(st_point==0)
				{
					push(i);
					break;
				}
				prev=topest();
			}
			if(a[i]>=a[prev])
			{
				push(i);
			}
		}
		int ans[n+1];
		i=1;//change done i=0
		while(i<=n)
			ans[i++]=-1;
		i=0;
		while(i<n)
		{
			int temp=R[i]-L[i]-1;
			ans[temp]=max(ans[temp], a[i]);
			i++;
		}
		i=n-1;
		while(i>0)
		{
			ans[i]=max(ans[i],ans[i+1]);
			i--;
		}
		for(i=1;i<n;i++)
				printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
		st_point=0;
	}
	return 0;
}
