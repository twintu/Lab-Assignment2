/*Programe to implement SINGLY LINKEDLIST*/

#include<stdio.h>
#include<stdlib.h>

void insert(int);
void delete(int);
void display(void);
void search(int);

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;
node *head=NULL,*curr=NULL;

int main()
{
	int ch,item,m;
	do
	{
		printf("\n\n\tMenu\n\t------\n1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter the data to insert\n");
				scanf("%d",&item);
				insert(item);
				break;

			case 2: printf("\nEnter the data item to delete\n");
				scanf("%d",&item);
				delete(item);
				break;

			case 3: printf("\nEnter the data item to be search\n");
				scanf("%d",&item);
				search(item);
				break;

			case 4: display();
				break;

			case 5: break;
		}
	}while(ch!=5);
}


void insert(int item)
{
	node *newnode;				 
	newnode=(node *)malloc(sizeof(node));		//allocating memory to new node

	newnode->data=item;					//insert the item at the data field part
	newnode->next=NULL;					//insert null value at the end part

	if(head==NULL)
	{
		head=newnode;					//curr is the pointer pointing the last node of the list
		curr=head;
	}
	else
	{

		curr->next=newnode;
		curr=newnode;
	}
}


void delete(int item)
{

	node *nnode,*temp;
	if(head==NULL)				//if nothing in the linked list print list is empty
	{
		printf("The List is Empty\n");
		return;
	}

	if(head->data==item)			//search the item in the first postion        
	{
		temp=head;
		head=head->next;
		free(temp);
		return;
	}
	nnode=head;

	while(nnode->next->next!=NULL)		//search the item in the middle position 
	{
		if(nnode->next->data==item)
		{
			temp=nnode->next;			//if found move that element to a temporary node
			nnode->next=temp->next;
			free(temp);
			printf("The data %d is deleted\n",item);
			return;
		}

		else
		{
			nnode=nnode->next;
		}
	}

	if(nnode->next->data==item)			//search the data in the last position
	{
		temp=nnode->next;
		nnode->next=NULL;
		free(temp);
		printf("The data %d is deleted\n",item);
		return;
	}

	printf("The data %d is not found in the list\n",item);
	return;
}

void search(int item)
{
	node *nnode;
	nnode=head;
	while(nnode)
	{
		if(nnode->data==item)				//if item found print node found else print not found
		{
			printf("The data %d is found in the list\n",item);
			return;
		}
		nnode=nnode->next;
	}
	printf("The data %d is not found in the list\n",item);
}

void display()
{
	node *nnode;
	if(head==NULL)
	{
		printf("Empty list\n");				//print all the data in the list
		return;
	}
	nnode=head;
	while(nnode)
	{
		printf("%d->",nnode->data);
		nnode=nnode->next;
	}
}
