/*******************************************************
 * Author: Matthew Solbrack
 * Date: 04/04/2019
 * Subject: mergesort will take values from data.txt and 
 * arrange them using the merge sort functionality
 * *****************************************************/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void merge(int first, int last, int arr[])
{
	//if n = 1, done
	if (last <= first)
	{
		return;
	}
	
	//Recursively sort
	int mid = (first + last) / 2;
	merge(first, mid, arr);
	merge(mid+1, last, arr);

	//Merge the 2 sorted lists
	int placement;
	int left = first;
	int right = mid + 1;
	int temp[last+1];

	//Place numbers into temp array as its being merged
	for (placement = first; placement <= last; placement++)
	{
		if(left == mid + 1)
		{
			temp[placement] = arr[right];
			right++;
		}
		else if (right == last + 1)
		{
			temp[placement] = arr[left];
			left++;
		}
		else if (arr[left] < arr[right])
		{
			temp[placement] = arr[left];
			left++;
		}
		else
		{
			temp[placement] = arr[right];
			right++;
		}
	}

	//Move numbers from temp array to original array
	for (placement = first; placement <= last; placement++)
		arr[placement] = temp[placement];	 
}


int main()
{
	int temp, i=0, j=0, k, pos=0;
	int* arr;
	int * arrTemp;
	arr = malloc(100 * sizeof(int));
	arrTemp = malloc(100 * sizeof(int)); 
	FILE * textFile;
	FILE * mergeFile;

		
	if ((textFile = fopen("data.txt", "r"))) 
	{
		while ((fscanf(textFile, "%d", &arr[i])) != EOF) 
		{
			++i;
		}		
		fclose(textFile);
	}


	mergeFile = fopen("merge.txt", "w");

        if(!mergeFile)
        {
               printf("MergeFile Failed to Open");
               exit(-1);
         }

	while (j < i)
	{
		pos = arr[j];
		j++;
		for(k=0; k < pos; k++)
		{
			arrTemp[k] = arr[j];
			j++;	
		}
		
		merge(0, k-1, arrTemp);

		for(temp=0; temp < k; temp++)
		{
			fprintf(mergeFile, "%d ", arrTemp[temp]);
		}	
		fprintf(mergeFile, "\n");
	}
	
	free(arr);
	free(arrTemp);
	fclose(mergeFile);	
	return 0;
}
