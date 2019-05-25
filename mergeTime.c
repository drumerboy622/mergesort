/*********************************************************************
 * Author: Matthew Solbrack
 * Date: 04.06.2019
 * Subject: executing the merge sort algorithm 10 times and printing
 * the time it takes to execute.
 * *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
        int c, i=0, n, num[] = {500000, 50000, 250000, 72000, 320000, 100000, 75000, 450000, 90000, 400000};
        int arr[500000];
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
                merge(0, c-1, arr);
                //end the clock time
                algTime = clock() - algTime;
                //calculate the time in seconds
                time_taken = ((double)algTime)/CLOCKS_PER_SEC;

                printf("Size of array: %d | Time to execute(sec): %f \n", c, time_taken);

                i++;

        }
        return(0);
}

