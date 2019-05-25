make: insertsort.c mergesort.c 
	gcc -g -Wall -std=c99 -o insertsort insertsort.c
	./insertsort
	gcc -g -Wall -std=c99 -o mergesort mergesort.c 
	./mergesort

timefiles: insertTime.c mergeTime.c
	gcc -g -Wall -std=c99 -o insertTime insertTime.c 
	./insertTime
	gcc -g -Wall -std=c99 -o mergeTime mergeTime.c
	./mergeTime	
	

clean:
	rm insert.txt insertsort mergesort merge.txt insertTime mergeTime
