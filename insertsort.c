/***************************************************************
 * Author: Matthew Solbrack
 * Date: 04/06/2019
 * Subject: insertionsort will take values from data.txt And
 * arrange them using the insertion sort functionality
 * *************************************************************/
#include <stdlib.h>
#include <stdio.h>

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



int main()
{
        int temp, i = 0, j = 0, k, pos = 0;
        int* arr;
        int * arrTemp;
        arr = malloc(100 * sizeof(int));
        arrTemp = malloc(100 * sizeof(int));
        FILE * textFile;
        FILE * insertFile;


        if ((textFile = fopen("data.txt", "r")))
        {
                while ((fscanf(textFile, "%d", & arr[i]))!= EOF)
                {
                        ++i;
                }
                fclose(textFile);
        }


        insertFile = fopen("insert.txt", "w");

        if (!insertFile)
        {
               printf("Insert File Failed to Open");
               exit(-1);
         }

        while (j < i)
        {
                pos = arr[j];
                j++;
                for (k = 0; k < pos; k++)
                {
                        arrTemp[k] = arr[j];
                        j++;
                }
		insertSort(arrTemp, k);

                for (temp = 0; temp < k; temp++)
                {
			fprintf(insertFile, "%d ", arrTemp[temp]);
                }
                fprintf(insertFile, "\n");

        }

	free(arr);
	free(arrTemp);
        fclose(insertFile);
        return 0;
}
