#include<stdio.h>
int arr[10]={10,9,8,7,6,5,4,3,2,1};
int size=10;
int quicksort(int st, int end)
{
	if(st>=end)
	{
		return;
	}
	int pivot= st;
	int next= st+1;
	int a=0,s=0,i;
	while(next<end)
	{
		for(i=next;i<=end;i++)
		{
			if(arr[next]>arr[i])
			{
				int temp= arr[i];
				arr[i]=arr[next];
				arr[next]=temp;
				next++;
				break;
			}
		}
	}
	int x;
	int h;
	int piv=arr[pivot];
	int j=0;
	for(i=1;i<size;i++)
	{
		if(arr[i]<piv)
		{
			int temp = arr[i-1];
			arr[i-1]=arr[i];
			arr[i]=temp;
		}
	}
	printf("arr= ");
	for(x=0;x<10;x++)
	{
		printf("%d ",arr[x]);
	}
	printf("\n");
	printf("*************************\n");
	quicksort(st,s-1);
	quicksort(s+1,end);
}
int main()
{
	quicksort(0,9);
}
