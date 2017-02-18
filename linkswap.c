#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int roll;
	struct student* next;
}Student;
Student *start;
Student *prevX;
Student *headX;
Student *headY;
Student *prevY;
int print(Student * head)
{
	if(head->next==NULL){
		printf("%d",head->roll);
		printf("\n");
		return 0;
	}
	printf("%d ",head->roll);
	head=head->next;
	return print(head);
}
int swap(int x, int y)
{
	if(headX->next != headY)
	{	
		printf("not consecutive\n");	
	        if(prevX==NULL && headY->next==NULL)
		{
			Student *temp=headX;
			start=headY;
			start->next=headX->next;
			prevY->next=headX;
			headX->next=NULL;
		}
		else if(prevX==NULL )
		{
			printf("first\n");
			Student *temp;
			start=headY;
			temp=headY->next;
			headY->next= headX->next;
			headX->next->next= headX;
			headX->next=temp;
		}
		else 
		{
			Student *temp= headX;
			prevX->next=headY;
			Student *temp2=headY->next;
			headY->next=headX->next;
			prevY->next=headX;
			headX->next=temp2;
		}
	}
	else if(headX->next == headY)
	{
		if(prevX==NULL )
		{
			Student *temp=start;
			start = headY;
			Student *temp1= headY->next;
			start->next=prevY;
			prevY->next= temp1;
		}
		else
		{
			Student *temp=headY->next;
			prevX->next=headY;
			headY->next=headX;
			headX->next=temp;
		}
	}
}
int searchX(int num, Student *prevhead, Student *head)
{
	if(head==NULL)
	{
		printf("X NOT FOUND\n");
		return 0;
	}
	if(head->roll==num)
	{
		headX=head;
		prevX=prevhead;
		printf("------------------------------\n");
		printf("X FOUND \n");
		printf("prevx=%p headx=%p\n",prevX,headX);
		printf("------------------------------\n");
		return 1;
	}
	prevhead= head;
	head=head->next;
	return searchX(num,prevhead,head);
}
int searchY(int num, Student *prevhead, Student *head)
{
	if(head==NULL)
	{
		printf("Y NOT FOUND\n");
		return 0;
	}
	if(head->roll==num)
	{
		headY=head;
		prevY=prevhead;
		printf("------------------------------\n");
		printf("Y FOUND \n");
		printf("prevy=%p heady=%p\n",prevY,headY);
		printf("------------------------------\n");
		return 1;
	}
	prevhead= head;
	head=head->next;
	return searchY(num,prevhead,head);
}
int main()
{
	Student *head = NULL;
	int i,n;
	unsigned int_size = sizeof(int);
	scanf("%d",&n);
	printf("write the numbers to be enteres\n");
	for(i=0;i<n;i++)
	{
		Student *temp= (Student*)malloc(sizeof(Student));
		scanf("%d",&temp->roll);
		temp->next= head;
		head=temp;
	}
	start=head;
	print(start);
	int m,num,findX,findY,x,y,it;
	printf("write the number of iterations\n");
	scanf("%d",&it);
	for(i=0;i<it;i++)
	{
		printf("write x and y\n");
		scanf("%d %d",&x,&y);
		findX=searchX(x,NULL,start);
		findY=searchY(y,NULL,start);
		if(findX==0 || findY==0)
		{
			printf("INVALID INPUT\n");
			print(start);
		}
		else 
		{
			printf("swapping x and y\n");
			swap(x,y);
			print(start);
		}
	}

	return 0;
}
