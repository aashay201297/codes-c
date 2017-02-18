// sum(l,r) and update
// index=index of segtree where we call update
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define p(x) printf("%lld\n",x)
#define s(x) scanf("%lld",&x)
typedef struct Node{
	long long ver;
	struct Node *next;
}node;

node *arr[500005];
long long n,time=0,MAX=20000000000;
long long st[8000005],start[500005],finish[500005];
long long seg_tree[500004],vis[500005],seg_arr[2000005];
long long min(long long a,long long b)
{
	return (a>b)? b:a;
}
int sum(int a, int b)
{
	a+=b;
	b+=a;
	return a+b;
}
void update(long long index,long long l,long long r, long long x, long long vl)
{
	if(l==r)
	{
		if(vl < st[index])
			st[index] = vl;
		return;
	}
	long long lc=2*index, rc=lc+1;
	long long m=(l+r)/2;
	if(x<=m) update(lc,l,m,x,vl);
	else update(rc,m+1,r,x,vl);
	//when right and left child are successfully updated, update parent i.e. st[index];
	st[index]=min(st[lc],st[rc]);
}
//L,R is the query for which we require sum
//l, r  is the range of indices whose sum st[index] stores.
long long query(long long index,long long l, long long r, long long L, long long R)
{
	if(r<L || R<l || r<l) return INT_MAX;
	if(L<=l && r<=R) return st[index];
	long long lc=2*index;
	long long rc=lc+1;
	long long m=(l+r)/2;
	return min(query(lc,l,m,L,R),query(rc,m+1,r,L,R));
}

long long time_stamp(long long i)
{
	vis[i]=1;
	start[i]=++time;
	node *p=arr[i];
	while(p!=NULL)
	{
		if(vis[p->ver]==0)
			time_stamp(p->ver);
		p=p->next;
	}
	finish[i]=++time;
	return 0;
}
//long long find()
long long build_st(long long index,long long l,long long r)
{
	//	printf("index=%lld; %lld-%lld\n",index,l,r);
	if(l==r)
	{
		st[index]=seg_arr[l];
		//printf("st[%lld]=%lld\n",l,st[l]);
		return 0;
	}
	long long lc=2*index, rc=lc+1;
	long long m=(l+r)/2;
	build_st(lc,l,m);
	build_st(rc,m+1,r);
	//printf("st[%lld] = %lld; st[%lld]=%lld\n",lc,st[lc],rc,st[rc]);
	st[index]=min(st[lc],st[rc]);
	//	printf("st[%lld]=%lld\n",index,st[index]);
	//when right and left child are successfully updated, update parent i.e. st[index];
}


int main()
{
	long long i,j,u,v,ans,q;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		arr[i]=NULL;
	}
	for(i=1;i<=4*n;i++)
	{
		st[i]=INT_MAX;
		seg_arr[i]=INT_MAX;
	}
	for(i=1;i<=n;i++)
	{
		node *temp=(node *)(malloc(sizeof(node)));
		arr[i]=temp;
		temp->ver=i;
		temp->next=NULL;
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		node *t;
		t=(node *)(malloc(sizeof(node)));
		t->next=arr[u]->next;
		t->ver=v;
		arr[u]->next=t;
		node *j;
		j=(node *)(malloc(sizeof(node)));
		j->next=arr[v]->next;
		j->ver=u;
		arr[v]->next=j;

	}
	i=1;
	while(i<=n)
	{
		s(seg_tree[i]);
		i++;
	}
	time_stamp(1);
	for(i=1;i<=n;i++)
	{
		seg_arr[start[i]]=min(seg_tree[i],seg_arr[start[i]]);
		seg_arr[finish[i]]=min(seg_tree[i],seg_arr[start[i]]);
		//sum(1,0);
	}
	for(i=1;i<=n;i++)
	{
		printf("i=%lld star=%lld end=%lld\n",i,start[i],finish[i]);
	}
	build_st(1,1,2*n);
	for(i=1;i<=q;i++)
	{
		long long p,x,cas,r,inp;
		s(inp);
		switch(inp)     
		{
			case 0: s(x);
				s(v);
				update(1,1,2*n,start[x],v);
				update(1,1,2*n,finish[x],v);
			case 1: s(x);
				ans=query(1,1,2*n,start[x],finish[x]);
				p(ans);
				//sum(3,2);
		}
	}
	return 0;
}
