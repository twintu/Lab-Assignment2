
/*Program of queue using array*/
/*Concept used here is FIFO(First In First Out),here two operations are there,insertion and deletion*/
/*Insertion takes place at rear end and deletion takes place at front end */




# include <stdio.h>
# define SIZE 20

int queue_array[SIZE],rear=-1,front=-1;

void insert();
void delete();
void display();

int main()
{
	int choice;
	do
	{
		printf("\n\tMENU\n\t******\n1.INSERT\n2.DELETE\n3.DISPLAY \n4.EXIT\nEnter your choice") ;	
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :insert();
				break;

			case 2 :delete();
				break;

			case 3 :display();
				break;

			case 4 :break;
		}

	}while(choice!=4);

	return;
}

void insert()
{
	int item;

	if (rear==SIZE-1)			//if queue is full print overflow

	{
		printf("Queue Overflow\n");
	}

	else
	{
		if (front==-1) 			//if queue is initially empty 
		{
			front=0;
		}

		printf("\nEnter the element to be added: ");
		scanf("%d",&item);

		rear=rear+1;			//increment the rear and insert the item into rear end
		queue_array[rear] =item ;
	}
}


void delete()
{

	if (front == -1 || front > rear)	//if queue is empty the print underflow		
	{
		printf("Queue Underflow\n");
		return ;
	}

	else
	{
		printf("Element deleted from queue is : %d\n", queue_array[front]);		//inorder to delete the item from queue 												increment the postion of front
		front=front+1;
	}

} 


void display()
{
	int i;

	if (front == -1)
	{
		printf("Queue is empty\n");
	}

	else
	{
		printf("Queue is :\n");					//print the element in the queue ie,from front to rear
		for(i=front;i<= rear;i++)
		{
			printf("%d ",queue_array[i]);
		}

		printf("\n");
	}
}
