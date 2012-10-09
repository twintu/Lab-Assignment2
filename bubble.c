/*Program to Sort element using Bubble Sort*/  

#include<stdio.h>   


int main()   
{   

	int array[20],n,i,j,temp;   

	printf("\nEnter the limit: ");   
	scanf("%d",&n);   

	printf("\nEnter the elements: ");       
	for( i=0;i<n;i++)   		//read the element of array to be sorted
	{ 

		scanf("%d",&array[i]);   
	}   


	for(i=0; i<n; i++)
	{

		for(j=0; j<n-1; j++)
		{
			if(array[j]>array[j+1])		//check if a[j]>a[j+1]
			{
				temp = array[j+1];
				array[j+1] = array[j]; 	//if true interchange the position of a[j] and a[j+1]
				array[j] = temp;
			}
		}
	}

	printf("\n\nSorted array is:\n");   

	for( i=0;i<n;i++)   
	{
		printf("\n%d\n",array[i]);   
	}
	return 0; 
}


