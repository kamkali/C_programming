#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.h"
void quicksort(void * base, int left, int right, size_t size, int(compare)(const void*,const void*)) {


	int i = left;
	int j = right;

	void* pivot = (void*)malloc(size);

	memcpy(pivot, (void*)(base + (((left + right) / 2)*size)), size);



	do {
		while (compare(pivot,(void*)(base + i * size))) i++;
		while (compare((void*)(base + j * size),pivot)) j--;
		if (i <= j) {

			void* temp = (void*)malloc(size);
			memcpy(temp, (void*)(base + i * size), size);
			memcpy((void*)(base + i * size), (void*)(base + j * size),size);
			memcpy((void*)(base + j * size), temp,size);


			i++;
			j--;

			free(temp);
		}
	} while (i <= j);

	free(pivot);

	if (left<j) quicksort(base, left, j,size,compare);
	if (right>i) quicksort(base, i, right,size,compare);

}
#endif
