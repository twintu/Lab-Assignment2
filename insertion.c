/*Sort the element using Insertion Sort*/

#include<stdio.h>


int main()
{
	int n,array[20],i,j,key;
	printf("\nEnter the limit");
	scanf("%d",&n);

	printf("\nEnter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);		//read the array of element to be sorted
	}


	for(i=0;i<n;i++)
	{
		key = array[i];				//set first element as key and j=i-1
		j= i-1;

		while(j>=0 && array[j]>key)		//check if j>0 and element greater than key
		{
			array[j+1] = array[j];		 //if true store the value of a[j] in a[j+1] position

			j--;				//decrement j value and store the key value in array[j+1]
		}

		array[j+1] = key;			
	}


	printf("\nSorted elements are:");
	for(i=0;i<n;i++)
	{
		printf("\n%d\n ",array[i]);
	}

	printf("\n");
	return 0;
}
