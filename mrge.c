/*Sort an array of element using Merge Sort*/

#include<stdio.h>



int main()
{
	int array[20],n,i;

	printf("\nEnter the limit:");
	scanf("%d",&n);

	printf("\nEnter the element to be sorted:");

	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	partition(array,0,n-1);			//call the partition function inorder to divide the array


	printf("\nThe Sorted array is\n");

	for(i=0;i<n;i++)
	{
		printf("%d\n",array[i]);
	}
	return;
}



int partition(int array[],int low,int high)
{
	int mid;

	if(low<high)
	{
		mid=(low+high)/2;				//calculate the mid point

		partition(array,low,mid);			//divide the element in an array into 2 part
		partition(array,mid+1,high);

		sort(array,low,mid,high);			//call the sort function
	}
	return;
}


int sort(int array[],int low,int mid,int high)
{
	int i,j,k,l,array2[20];
	l=low;

	i=low;							//initialize the variable
	j=mid+1;

	while((l<=mid)&&(j<=high))						
	{
		if(array[l]<=array[j])				//compare the lower and the middle value
		{
			array2[i]=array[l];					//if true copy the lower content to array2
			l++;
		}

		else
		{
			array2[i]=array[j];					//else copy the corresponding element to array2
			j++;
		}

		i++;
	}

	if(l>mid)
	{
		for(k=j;k<=high;k++)
		{
			array2[i]=array[k];
			i++;
		}
	}

	else
	{
		for(k=l;k<=mid;k++)
		{
			array2[i]=array[k];
			i++;
		}
	}

	for(k=low;k<=high;k++)					//all the sorted element again copied back to array1
	{
		array[k]=array2[k];
	}
	return;
}






