/*Program to implement Double Linked List*/


#include<stdio.h>
#include<stdlib.h>

void insert_beg();
void insert_mid();
void insert_end();
void deletion();
void search();
void display();

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start;


int main()
{
	int choice; start=NULL;
	do
	{
		printf("\n\tMenu\n\t-------\n1.Insertion at the beginning\n2.Insertion at Middle\n3.Insertion at End\n4.Delete\n5.Search\n6.Display\n7.Exit\n\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_beg();
			       break;

			case 2:insert_mid();
			       break;

			case 3:insert_end();
			       break;

			case 4:deletion();
			       break;

			case 5:search();
			       break;

			case 6:display();
			       break;

			case 7:break;

		}

	}while(choice!=7) ;

	return;
}

void insert_beg(void)          // insert element at the beginning of double link list
{
	int item;

	struct node *nnode;
	nnode=(struct node *)malloc(sizeof(struct node));

	printf("\nenter data to insert :");
	scanf("%d",&nnode->data);

	item=nnode->data;

	if(start==NULL)                    //if Linked list is empty insert the data in start node
	{
		nnode->prev=nnode->next=NULL;
		start=nnode;
	}

	else
	{
		nnode->next=start;		//else point to previous field of start node and add the item to start position       																(beginning)
		nnode->prev=NULL;
		start->prev=nnode;
		start=nnode;
	}

	printf("\n%d is inserted at the beginning\n",item);
	return;
}


void insert_end(void)          // insert element at the End of double link list
{
	int item;
	struct node *nnode2,*lp;

	nnode2=(struct node *)malloc(sizeof(struct node));   //allocate the memory for new node

	printf("\nenter data to insert:");			   //read the item
	scanf("%d",&nnode2->data);

	item=nnode2->data;

	if(start==NULL)					//if nothing in the list insert the element at the start node
	{
		nnode2->prev=nnode2->next=NULL;
		start=nnode2;
	}
	else
	{
		lp=start;					//else insert the data after the previous node(end postion)
		while(lp->next!=NULL)
		{
			lp=lp->next;
		}
		nnode2->prev=lp;
		lp->next=nnode2;
		nnode2->next=NULL;
	}
	printf("\n%d is inserted in the list\n",item);
	return;
}



void insert_mid(void)       				 // insert element before the given element of Linked list
{
	struct node *nnode1,*temp,*ptemp;
	int item,data1;
	if(start==NULL)
	{
		printf("\nlinked list is empty\n"); 
		return;
	}
	printf("\nenter data before which new node is to be insreted\n");
	scanf("%d",&item);

	if(item==start->data)					//if item is at the start position call insert_beg function
	{
		insert_beg();
		return;
	}

	ptemp=start;						
	temp=start->next;

	while(temp!=NULL&&temp->data!=item)
	{
		ptemp=temp;
		temp=temp->next;
	}

	if(temp==NULL)						//if item not in the list print item not found
	{
		printf("\n%d data does not exist\n",item);
	}

	else
	{
		nnode1=(struct node *)malloc(sizeof(struct node));	//allocate a memory for the new node

		printf("\nenter data to insert :");			//read the new data
		scanf("%d",&nnode1->data);

		data1=nnode1->data;					//insert the data after the corresponding node
		nnode1->prev=ptemp;
		nnode1->next=temp;
		ptemp->next=nnode1;
		temp->prev=nnode1;

		printf("\n%d is inserted\n",data1);
	}
	return;
}


void deletion(void)
{
	struct node *pointer,*temp,*nt;
	int item;

	if(start==NULL)
	{
		printf("\nLinked List is empty\n");
		return;
	}

	printf("\nenter data to be deleted");		//read the item to delete
	scanf("%d",&item);

	if(item==start->data)				//if item found at the beginning node move that data to a temperary node
	{
		temp=start;
		start=start->next;
		free(temp);
		printf("\n%d is deleted from the list\n",item);

		if(start!=NULL)
		{
			start->prev=NULL;
		}
		return;
	}
	pointer=start;
	temp=start->next;

	while(temp!=NULL&&temp->data!=item)
	{
		pointer=temp;
		temp=temp->next;
	}

	if(temp==NULL)
	{
		printf("\n%d does not exist\n",item);
		return;
	}

	else
	{
		pointer->next=temp->next;
		//check if the node is present in the position other than beginning
		if(temp->next!=NULL)
		{
			nt=temp->next;
			nt->prev=pointer;
		}
		free(temp);
	}
	printf("\n%d is deleted from the list\n",item);
	return;
}


void display(void)
{
	struct node *temp;
	if(start==NULL)				//if nothing in the list print list is empty
	{
		printf("\nList is empty\n");
		return;
	}

	printf("\nThe List is:\n");		//else print the data in the list
	temp=start;

	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return;
}



void search(void)
{
	struct node *pointer,*temp,*nt;
	int item;

	if(start==NULL)
	{
		printf("\nLinked List is empty\n");
		return;
	}

	printf("\nenter data to search");		//read the item to search
	scanf("%d",&item);

	if(item==start->data)				//check if item is at the beginning node 
	{
		printf("\n%d is found in the list\n",item);

		if(start!=NULL)
		{
			start->prev=NULL;
		}
		return;
	}
	pointer=start;
	temp=start->next;

	while(temp!=NULL&&temp->data!=item)
	{
		pointer=temp;
		temp=temp->next;
	}

	if(temp==NULL)
	{
		printf("\n%d not found\n",item);
		return;
	}

	else
	{
		pointer->next=temp->next;
		//check if the node is present in the position other than beginning
		if(temp->next!=NULL)
		{
			nt=temp->next;
			nt->prev=pointer;
		}

	}
	printf("\n%d is found in the list\n",item);
	return;
}

