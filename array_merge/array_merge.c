#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values);
int occurrencesOf(int value, int* values);
int* flattenArrayOfArrays(int** arrayOfArrays, int* flatArray);

int* array_merge(int num_arrays, int* sizes, int** values) {

  int sizeOfValues = 0;
  for (int i = 0; i < num_arrays; i++) {
    sizeOfValues = sizeOfValues + sizes[i];
  }

  int* dupResult = (int*) calloc(sizeOfValues, sizeof(int));

  // put all elements into a 1D array called dupResult (contains duplicate elements)
  flattenArrayOfArrays(num_arrays, sizes, values, dupResult);

  // sort the result containing duplicates
  mergesort(dupResultSize, dupResult);




  // result: sorted list
}

int* flattenArrayOfArrays(int num_arrays, int* sizes, int** arrayOfArrays, int* flatArray) {

  // for every inner array, add every element to flattened array.
  flatIndex = 0;
  int i;
  for (i = 0; i < num_arrays; i++) {
    int j;
    for (j = 0; j < sizes[i]; j++) {
      flatArray[flatIndex] = values[i][j];
      flatIndex++;
    }
  }

  return flatArray;
}
