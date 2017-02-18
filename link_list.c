#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int roll;
	struct student* next;
}Student;
Student *start;
/*int delete(Student* head)//,Student *before_head)
  {
  if(head->next == NULL)
  free(head);
//before_head=head->next;
//free(head);
}*/
int search(int num, Student *head)
{
	if(head==NULL)
	{
		printf("NOT FOUND\n");
		return 0;
	}
	if(head->roll==num)
	{
		printf("FOUND \n");
		/*delete(head);
		  printf("AND DELETED");*/
		return 1;
	}
	head=head->next;
	return search(num,head);
}
int delfirst()
{
	printf("deleting first element\n");
	Student *temp=start->next;
	free(start);
	start=temp;
	printf("starting by %d\n",start->roll);
	return 0;
}
int dellast()
{
	printf("deleting last element\n");
	Student *beforehead=NULL;
	Student *head=start;
	while(head != NULL)
	{
		if(head->next==NULL)
		{
			free(head);
			beforehead->next=NULL;
			return 0;
		}	
		beforehead=head;
		head=head->next;
	}
	printf("starting by %d\n",start->roll);
}
int delete(int count)
{
	printf("deleting element number %d\n",count);
	Student *beforehead=NULL;
	Student *head=start;
	int temp=1;
	while(head!=NULL)
	{
		if(count==1)
		{
			Student *temp1=head->next;
			free(head);
			start=temp1;
			break;
		}
		else if(count==temp)
		{
			beforehead->next=head->next;
			free(head);		
			break;	
		}
		beforehead=head;
		head=head->next;
		temp++;
	}
	printf("starting by %d\n",start->roll);

}
int insertstart(int data)
{
	printf("inserting %d at the start\n",data);
	Student *temp = (Student *)malloc(sizeof(Student));
	Student *temp2=start;
	start=temp;
	start->next=temp2;
	start->roll=data;
	printf("starting by %d\n",start->roll);
	return 0;
}
int insertlast(int data)
{
	printf("inserting %d at the last\n",data);

	Student *temp = (Student *)malloc(sizeof(Student));
	Student *beforehead=NULL;
	Student *head=start;
	int c=1;
	while(head->next!=NULL)
	{
		beforehead=head;
		head=head->next;
		printf("c=%d\n",c);
		c++;
	}
	head->next=temp;
	temp->next=NULL;
	temp->roll=data;
	printf("starting by %d\n",start->roll);
	return 0;
}
int print(Student *head)
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	while(head!=NULL)
	{
		printf("%d ",head->roll);
		head=head->next;
	}
	printf("\n-------------------------\n");
	return 0;
}
int main()
{
	Student *head = NULL;
	int i,n;
	unsigned int_size = sizeof(int);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		Student *temp= (Student*)malloc(sizeof(Student));
		scanf("%d",&temp->roll);
		temp->next= head;
		head=temp;
	}
	start=head;

	print(start);
	int m,num,found;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&num);
		found=search(num,start);
	}
	int x,y;
	print(start);
	printf("how many queries?\n");
	int it;
	scanf("%d",&num);
	for(i=0;i<it;i++)
	{
	printf("what you wanna do?\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:delfirst();
		       break;
		case 2:dellast();
		       break;
		case 3:printf("which position to delete\n");
		       scanf("%d",&y);
		       delete(y);
		       break;
		case 4:printf("number to be added at the last\n");
		       scanf("%d",&y);
		       insertlast(y);
		       break;
		case 5:printf("number to be added at the startn\n");
		       scanf("%d",&y);
		       insertstart(y);
		       break;
	}
	print(start);
	}
	/*delfirst();
	print(start);
	
	dellast();
	print(start);

	delete(2);
	print(start);

	insertlast(3);
	print(start);

	insertstart(7);*/
	print(start);

	return 0;
	/*printf("the linked list is\n");
	  printList();*/

}
