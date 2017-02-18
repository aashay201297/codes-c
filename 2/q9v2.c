#include<stdio.h>
int l=1,r=1;
int a[1000001];
int q[1000001];
int insertright(int n)
{
	q[r]=n;
	if(r==1000000)
	{
		r=1;
		return 0;
	}
	r++;
	return 0;
}
int insertleft(int n)
{
	if(l==1)
	{
		//printf("l-1<=0\n");
		q[1000000]=n;
		l=1000000;
		//printf("arr[%d]=%d\n",l-1,arr[l-1]);
		return 0;
	}
	l--;
	q[l]=n;
	return 0;
}
int deleteleft()
{
	if(l==1000000)
	{
		l=1;
		return 0;
	}
	l++;
	return 0;

}
int deleteright()
{
	if(r==1)
	{
		r=1000000;
		return 0;
	}
	r--;
	return 0;
}
int q_empty()
{
	if(l==r)
		return 1;
	return 0;
}
int empty()
{
	l=1;
	r=1;
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,n,i;
		l=1;
		r=1;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<n-1;i++)
		{
			if(q_empty()==1)
				insertright(i);
			else
			{
				int flag=0;
				if(r==1)
				{
					if(a[i]<a[q[1000000]])
					{
						empty();
						insertright(i);
						flag=1;
					}
				}
				else 
				{
					if(a[i]<a[q[r-1]])
					{
						empty();
						insertright(i);
						flag=1;
					}
				}
				if(flag!=1)
				{
					if(a[i]<a[q[l]]) 
					{
						while(a[i]<a[q[l]])
						{
							deleteleft();
						}
						insertleft(i);
					}
					else 
						insertleft(i);
				}
			}
			if(i>=k)
			{
				if(r==1)
				{
					a[i+1]=a[q[1000000]]+a[i+1];
				}
				else 
				{
					a[i+1]=a[q[r-1]]+a[i+1];
				}
				if(r==1)
				{
					if(q[1000000]==i-k+1)
						deleteright();
				}
				else if(q[r-1]==i-k+1)
					deleteright();
			}
		}
		int ans=a[n-1]+a[0];
		printf("%d\n",ans);
	}
}
