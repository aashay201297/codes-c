#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int roll;
	struct student* next;
}Student;
Student *start;
int delete(Student *head,int num)
{
	if(start->roll==num)
	{
		Student *temp= start->next;
		free(start);
		start=temp;
		return 1;
	}
	else if(head->next->next == NULL)
	{
		free(head->next);
		head->next=NULL;
		return 1;
	}
	else if(head->next->roll == num)
	{
		Student * temp= head->next->next;
		free(head->next);
		head->next=temp;
		return 1;
	}
	head=head->next;
	return delete(head,num);
}
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
int search(int num, Student *head)
{
	if(head==NULL)
	{
		printf("NOT FOUND\n");
		print(start);
		return 0;
	}
	if(head->roll==num)
	{
		printf("FOUND ");
		delete(start,head->roll);
		printf("AND DELETED\n");
		print(start);
		return 1;
	}
	head=head->next;
	return search(num,head);
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
	return 0;
}
