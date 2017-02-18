#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int roll;
	struct student* next;
}Student;
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
	int m,num,found;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&num);
		found=search(num,head);
	}
	return 0;
	/*printf("the linked list is\n");
	printList();*/
	
}
