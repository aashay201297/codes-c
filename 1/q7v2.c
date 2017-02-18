#include<stdio.h>
int main()
{
	int t,n,k,q,c[100005],w[100005],cum_w[100005],cum_c[100005];
	scanf("%d",&t);
	while(t--)
	{
		int i;
		scanf("%d %d %d",&n,&k,&q);
		cum_w[0]=0;
		cum_c[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			cum_w[i]=w[i]+cum_w[i-1];
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			cum_c[i]=c[i]+cum_c[i-1];
		}
		//printf("weight cumu:\n");
		//for(i=1;i<=n;i++)		
		//	printf("%d ",cum_w[i]);
		//printf("\n");
		/*printf("cost cumu:\n");
		for(i=1;i<=n;i++)		
			printf("%d ",cum_c[i]);
		printf("\n");*/
		int cost=0,mid,l,r,max=-876544;
		for(i=n-k+1;i>1;i--)
		{
			int weight = cum_w[i+k-1] - cum_w[i-1],flag=0;
			//printf("weight=%d\n",weight);
			l=1; r=i-1;
			cost=0;
			if(i!=n-k+1)
			{
				cost+=cum_c[n]-cum_c[i+k-1];
				//printf("i=%d cost=%d\n",i,cost);
				//printf("cum_w[%d]=%d\n",i-1,cum_w[i-1]);
				//printf("l=%d r=%d\n",l,r);
			}
			/*while(l<=r)
			{
				flag=0;
				mid=(l+r)/2;
				int midsum=cum_w[i-1]-cum_w[mid-1];
				if(cum_w[i-1]*q<weight)
				{
					flag=1;
					cost=0;
					//printf("cum less than first\n");
					break;
				}
				else if(mid==l)
				{
					//printf("mid=l\n");
					if(((c[l]+c[r])*q) >= weight && c[r]*q < weight)
					{
						cost+= cum_c[i-3];
						break;
					}
					else 
					{
						cost+= cum_c[l];
						break;
					}
				}
				else if((midsum * q)==weight)
				{
					cost+=cum_c[mid-1];
					//printf("equal to\n");
					break;
				}
				else if((midsum * q)>weight)
				{
					l=mid;
					//printf("greater than\n");
					if((cum_w[i-1]-cum_w[mid]*q)<weight)
					{
						cost+=cum_c[l-1];
						//printf("agla less than\n");
						break;
					}
				}
				else
				{
					r=mid-1;
					//printf("else mein\n");
				}
				printf("cost=%d\n",cost);
			}*/
			//printf("cost at %d = %d\n",i,cost);
			while(l<=r)
			{
				int l,r;
				int mid=(l+r)/2;
				l=1;r=i-1;
				int midsum=cum_w[i-1]-cum_w[mid-1];
				if(l==r)
				{
					if(cum_w[l]*q >= weight)
					{
						break;
					}
				}
				else if(cum_w[i-1]<weight)
				{
					cost=0;
					break;
				}
				else if(l==r+1)
				{
					if((c[i-1]+c[i-2])*q >= weight && c[i-1]*q<weight )
					{
						cost+=cum_c[i-3];
						break;
					}
					else if((c[i-1]+c[i-2])*q >= weight && c[i-1]*q>=weight)
					{
						cost+=cum_c[i-2];
						break;
					}
				}
				else if((midsum * q)==weight)
				{
					cost+=cum_c[mid-1];
					//printf("equal to\n");
					break;
				}
				else if((midsum * q)>weight)
				{
					l=mid;
					//printf("greater than\n");
					if((cum_w[i-1]-cum_w[mid]*q)<weight)
					{
						cost+=cum_c[l-1];
						//printf("agla less than\n");
						break;
					}
				}
				else
				{
					r=mid-1;
					//printf("else mein\n");
				}
				
			}
			if(cost>max)
				max=cost;
		}
		printf("%d\n",max);
	}
}
