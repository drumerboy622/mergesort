/*********************************************************************
 * Author: Matthew Solbrack
 * Date: 04.06.2019
 * Subject: executing the insert sort algorithm 10 times and printing 
 * the time it takes to execute.
 * *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int arr[], int size)
{
	int loc = 1;
	int num, cur, comp;
	while(loc < size)
	{
		num = arr[loc];
		comp = loc - 1;
		cur = loc;
		
		while(comp >= 0 && arr[comp] > arr[cur])
		{
			arr[cur] = arr[comp];
			arr[comp] = num;
			comp--;
			cur--;
		}

		loc++;
	}
}

int main() {
	int c, i=0, n, num[] = {50000, 5000, 25000, 7200, 32000, 10000, 7500, 45000, 9000, 40000};
  	int arr[50000];
	double time_taken;
  	clock_t algTime;
 	
	// loop 10 times for all 10 numbers
 	while(i < 10)
 	{
		//randomly pick numbers for the array 
    		for (c = 0; c < num[i]; c++) 
    		{
       	 		n = rand() % 10000;
        		arr[c] = n;
    		}
    
		//record the clock time
    		algTime = clock();
		//call to function to sort
    		insertSort(arr, c);
		//end the clock time	
    		algTime = clock() - algTime;
		//calculate the time in seconds		
    		time_taken = ((double)algTime)/CLOCKS_PER_SEC;
    
   	 	printf("Size of array: %d | Time to execute(sec): %f \n", c, time_taken);
    
    		i++;
  
  	}


	return(0);
}
 
