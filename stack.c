/* Implentation of stack */
/*Concept used here is LIFO(Last In First Out.Here two operations are used:PUSH and POP*/
/*Both Push and Pop function is done from top of the stack*/

# include <stdio.h>
# define SIZE 20

int array[SIZE],top=-1,i ;

void push() ;
void pop() ;
void display() ;

int main()
{
	int ch ;
	do
	{
		printf("\n\tMENU\n\t*********\n1.PUSH\n2.POP\n3.Display \n4.Exit\nEnter your choice") ;	
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1 :push() ;		// if choice is 1 call push function
				break ;
			case 2 :pop() ;		//if choice is 2 call pop function
				break ;
			case 3 :display() ;		//if choice is 3 call display function
				break ;
			case 4 : 		//if choice is 4 exit from loop
				break ;
		}

	} while(ch != 4) ;
	return ;
}

void push()
{
	if(top==SIZE-1)			// if top=size print stack is full
	{
		printf("\nStack is full\n") ;
		return ;
	}
	top++ ;					//else increment the top and read the element to insert
	printf("\nEnter the element to PUSH : ") ;
	scanf("%d", &array[top]) ;
}


void pop()
{
	if(top == -1)					// if top=-1 print stack is empty
	{
		printf("\nStack is empty") ;
		return ;
	}
	printf("\nThe POP element is : %d\n", array[top]) ;	//else decrement the top 
	top-- ;
}

void display()
{
	if(top == -1)					// if top=-1 print stack is empty
	{
		printf("\nStack is empty") ;
		return ;
	}

	printf("\nThe elements in stack are :\n") ;	//else print the element from top to bottom

	for(i = top ; i>= 0;i--)
	{
		printf(" -> %d", array[i]) ;
	} 
	printf("\n") ;
	return;
}

