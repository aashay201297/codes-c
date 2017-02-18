#include<stdio.h>
int minheap[100005];
int maxheap[100005];
int lastmin=1;
int lastmax=1;
int min=0;
int max=0;
int insertmin(int a)
{
	minheap[lastmin]=a;
	lastmin++;
	min++;
	int l=(lastmin-1);
	while(minheap[l/2]>minheap[l] && l>1)
	{
		int temp=minheap[l/2];
		minheap[l/2]=minheap[l];
		minheap[l]=temp;
		l=l/2;
	}
}
int insertmax(int a)
{
	maxheap[lastmax]=a;
	lastmax++;
	max++;
	//heapify(last-1);
	int l=(lastmax-1);
	while(maxheap[l/2] < maxheap[l] && l>1)
	{
		int temp=maxheap[l/2];
		maxheap[l/2]=maxheap[l];
		maxheap[l]=temp;
		l=l/2;
	}
}
int deletemin()
{
	int temp=minheap[1];
	minheap[1]=minheap[lastmin-1];
	minheap[lastmin-1]=minheap[1];
	lastmin--;
	int p=1;
	while(p<=lastmin && 2*p<=lastmin && 2*p+1<=lastmin)
	{
		if(minheap[2*p] > minheap[2*p+1])
		{
			int temp=minheap[p];
			minheap[p]=minheap[2*p+1];
			minheap[2*p+1]=temp;
			p=2*p+1;
		}
		else if(minheap[2*p] < minheap[2*p+1])
		{
			int temp=minheap[p];
			minheap[p]=minheap[2*p];
			minheap[2*p]=temp;
			p=2*p;
		}
	}
	return temp;
}
int deletemax()
{
	int temp=maxheap[1];
	maxheap[1]=maxheap[lastmax-1];
	maxheap[lastmax-1]=maxheap[1];
	lastmax--;
	int p=1;
	while(p<=lastmax && 2*p<=lastmax && 2*p+1<=lastmax)
	{
		if(maxheap[2*p] > maxheap[2*p+1])
		{
			int temp=maxheap[p];
			maxheap[p]=maxheap[2*p+1];
			maxheap[2*p+1]=temp;
			p=2*p+1;
		}
		else if(maxheap[2*p] < maxheap[2*p+1])
		{
			int temp=maxheap[p];
			maxheap[p]=maxheap[2*p];
			maxheap[2*p]=temp;
			p=2*p;
		}
	}
	return temp;
}
int median(int num)
{
	if(num<maxheap[lastmax-1])
		insertmax(num);
	else 
		insertmin(num);
	if(min>max && min-max>1)
	{
		while(min-max>1)
		{
			int temp=deletemin();
			insertmax(temp);
		}
	}
	else if(min<max && max-min>1)
	{
		while(max-min>1)
		{
			int temp=deletemax();
			insertmin(temp);
		}
	}
	if(min==max)
		printf("%f\n",(float)(minheap[lastmin-1]+maxheap[lastmax-1])/2);
	else if(min>max)
		printf("%f\n",(float)minheap[lastmin-1]);
	else
		printf("%f\n",(float)maxheap[lastmax-1]);
}

int print(int arr[],int n)
{
	int i;
	for(i=1;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int n,i,x;
	int arr[10005];
	i=0;
	scanf("%d",&n);
	scanf("%d",&arr[0]);
	printf("%f \n",(float)arr[0]);
	scanf("%d",&arr[1]);
	printf("%f\n",(float)(arr[0]+arr[1])/2);
	if(arr[0]>arr[1])
	{
		insertmin(arr[0]);
		insertmax(arr[1]);
	}
	else 
	{
		insertmin(arr[1]);
		insertmax(arr[0]);
	}
	i=1;
	while(i<n)
	{
		scanf("%d",&arr[i]);
		median(arr[i]);
		i++;
	}
	print(minheap,lastmin);
	print(maxheap,lastmax);
	return 0;
}
