#include<stdio.h>
int g[100][100]={0};
int vis[1000]={0};
int n;
int num=1;
int dfs(int u, int num)
{
	int x;
	vis[u]=num;
	printf("%d ",u+1);
	for(x=0;x<n;x++)
	{	
		if(g[u][x]!=0 && !vis[x])
			dfs(x,num);
	}
}
int main()
{
	int i,m,x,y,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x-1][y-1]++;
		g[y-1][x-1]++;
	}
	printf("adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
	printf("\n");
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			ans=dfs(i,num++);
			//for(i=0;i<n;i++)
			//	vis[i]=0;
				printf("\n");
		}

	}
	/*for(i=1;i<=n*n;i++)
	{
		printf("%d ",vis[i]);
	}
	printf("\n");*/
	printf("num=%d\n",num-1);
}
