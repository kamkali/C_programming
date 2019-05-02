/*Plik naglókowy dla quicksort
Wykonali: Kamil Kalis, Jakub Burghardt, Daniel Jarosz */

#ifndef _QUICKSORT_H
#define _QUICKSORT_H

void quicksort(void * base, int left, int right, size_t size,
	      int(compare)(const void*,const void*));


#endif

