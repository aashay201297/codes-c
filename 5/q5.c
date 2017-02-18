#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long min(long long a, long long b)
{
	if(a>b)
		return b;
	return a;
}
long long min1(long long a, long long b, long long c, long long d)
{
	long long x[4];
	x[0]=a;
	x[1]=b;
	x[2]=c;
	x[3]=d;
	long long i;
	long long min=INT_MAX;
	for(i=0;i<3;i++)
	{
		if(x[i]<min)
			min=x[i];
	}
	return min;
}
long long main()
{
	long long n,i,j,l,k;
	char x;long long str[100005], dp[100005],q[100005];
	scanf("%lld",&n);
	char crap;
	scanf("\n");
	for(i=1;i<=n;i++)
	{
		scanf("%c",&x);
		long long temp= (long long)(x-'a'+1);
		str[i]=temp;
		scanf("%c",&x);
		while(x!='\n')
			scanf("%c",&x);
	}
	//prlong longf("%d\n",'a');
	//prlong longf("str=");
	/*for(i=1;i<=n;i++)
		prlong longf("%d ",str[i]);
	prlong longf("\n*******\n");*/
	dp[1]=0;
	dp[0]=100000000000;
	for(i=2;i<=n;i++)
	{
		dp[i]=100000000000;
		q[str[i]]=100000000000;
	}
	dp[n+1]=100000000000;
	//prlong longf("da=%d",d:p[n]);
	for(i=0;i<52;i++)
	{
		for(k=1;k<=26;k++)
			q[k]=100000000000;
		/*for(j=1;j<=n;j++)
		{
			q[str[j]]=min( q[str[j]], dp[j]);
		}*/
		for(l=1;l<=n;l++)
		{
			dp[l]=min(min(dp[l], dp[l-1]+1),min(dp[l+1]+1, q[str[l]]+1));
			//prlong longf("%d dp[%d]=%d ",q[str[l]]+1,l,dp[l]);
			q[str[l]]=min(q[str[l]],dp[l]);
		}
		//prlong longf("mid=%d\n",dp[n]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
