#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[200];
	scanf("%s",s);
	int q,i;
	scanf("%d",&q);
	int len=strlen(s);
	int hash[2000]={0},hash1[2000]={0};
	hash[0]=0;
	hash1[0]=0;
	for(i=1;i<=len;i++)
	{
		int temp=s[i-1];
		hash[i]=hash[i-1]+temp;	
	}
	hash1[len+1]=0;
	hash1[0]=0;
	for(i=len;i>0;i--)
	{
		int temp=s[i-1];
		hash1[i]=hash1[i+1]+temp;
	}
	while(q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if(hash[r]-hash[l-1] == hash1[l]-hash1[r+1])
		{
			printf("yes\n");
		}
		else 
			printf("no\n");
	}
	return 0;
}
