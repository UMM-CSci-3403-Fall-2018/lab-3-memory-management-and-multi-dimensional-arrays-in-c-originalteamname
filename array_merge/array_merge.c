#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mergesort.c"
#include "array_merge.h"


int* array_merge(int num_arrays, int* sizes, int** values);
int* removeDuplicates(int* array, int size);
int* flattenArrayOfArrays(int num_arrays, int* sizes, int** arrayOfArrays, int* flatArray);

int* array_merge(int num_arrays, int* sizes, int** values) {

  int sizeOfValues = 0;
  for (int i = 0; i < num_arrays; i++) {
    sizeOfValues = sizeOfValues + sizes[i];
  }

  int* dupResult = (int*) calloc(sizeOfValues, sizeof(int));

  // put all elements into a 1D array called dupResult (contains duplicate elements)
  flattenArrayOfArrays(num_arrays, sizes, values, dupResult);

  // sort the result containing duplicates
  mergesort(sizeOfValues, dupResult);

  int* result = removeDuplicates(dupResult, sizeOfValues);

  return result;
}

int* removeDuplicates(int* array, int size) {

  // determine size of deduped array
  // start numUniqueValues at 1 since we're assuming the first value to be
  // unique.
  int i;
  int numUniqueValues = 1;
  for(i = 1; i < size; i++) {
    if (array[i] != array[i-1]) {
      numUniqueValues++;
    }
  }

  int* result = (int*) calloc(numUniqueValues + 1, sizeof(int));
  result[0] = numUniqueValues;

  // start resultIndex to account for the size value
  int resultIndex = 1;

  int j;
  for(j = 1; j < size; j++) {
    if (array[j] != array[j-1]) {
      result[resultIndex] = array[j];
      resultIndex++;
    }
  }

  return result;
}

int* flattenArrayOfArrays(int num_arrays, int* sizes, int** arrayOfArrays, int* flatArray) {

  // for every inner array, add every element to flattened array.
  int flatIndex = 0;
  int i;
  for (i = 0; i < num_arrays; i++) {
    int j;
    for (j = 0; j < sizes[i]; j++) {
      flatArray[flatIndex] = arrayOfArrays[i][j];
      flatIndex++;
    }
  }

  return flatArray;
}
