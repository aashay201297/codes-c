#include<stdio.h>
#include<stdlib.h>
typedef struct Moka
{
	int l,r,v;
}moka;
moka a[100005],arr[100005];
long long vis[1000005],vis1[1000005];
int cmp(const void *a, const void *b)
{	
	moka *x=a;
	moka *y=b;
	return (y->v) - (x->v);
}
int main()
{
	long long t,i;
	scanf("%lld",&t);
	while(t--)
	{
		int n;
		int val[1000005],j,k;
		scanf("%d",&n);
		for(i=0;i<=1000000;i++)
		{
			vis[i]=-1;
			vis1[i]=-1;
			val[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld %lld",&a[i].l,&a[i].r,&a[i].v);
		}
		qsort(a,n,sizeof(moka),cmp);
		for(i=0;i<n;i++)
		{
			arr[i+1]=a[i];		
		}
		for(i=1;i<=n;i++)
		{
			int mokaval=arr[i].v;
			int start=arr[i].l;
			int end=arr[i].r-1;
			//printf("doing from %d to %d for %d\n",start,end,mokaval);
			/*for(k=0;k<25;k++)
				printf("%d->%d %d\n",k,vis[k],vis1[k]);
			printf("\n");*/
			while(start <= end)
			{
				//printf("vis[%d]=%d vis1[%d]=%d\n",start,vis[start],end,vis1[end]);
				if(vis[start]!=-1)
				{
					start=vis[start];
				}
				if(vis1[end]!=-1)
				{
					end=vis1[end];
				}
				if(vis[start]==-1 && vis1[end]==-1)
				{
					for(j=start;j<=end;j++)
					{
						if(val[j]==0)
						{
							val[j]=mokaval;
							vis1[j]=start-1;
							vis[j]=end+1;
						}
					}
				}
			}
		}
		//for(i=0;i<25;i++)
		//	printf("%d-> %d\n",i,val[i]);
		//printf("\n");
		int temp=0;
		for(i=1;i<=1000000;i++)
		{
			if(val[i]!=0)
			{
				j=i;
				temp=val[i];
				printf("%d %d\n",i,val[i]);
				break;
			}
		}
		for(i=j;i<=1000000;i++)
		{
			if(val[i]!=temp)			
			{	
				temp=val[i];
				printf("%d %d\n",i,val[i]);
				/*if(temp!=0)
				{
					j=i;
					size--;
				}*/
			}
			/*if(size==0 && val[j]!=temp)
			{
				printf("%d %d\n",j+1,val[j+1]);
				printf("done\n");
				break;
			}*/
		}
	}
	return 0;
}
