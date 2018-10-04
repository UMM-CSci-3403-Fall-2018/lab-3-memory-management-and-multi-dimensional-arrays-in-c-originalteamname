#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergesort.c"
#include "array_merge.h"

// Function prototypes
int* array_merge(int num_arrays, int* sizes, int** values);
int* removeDuplicates(int* array, int size);
int* flattenArrayOfArrays(int num_arrays, int* sizes, int** arrayOfArrays, int* flatArray);


int* array_merge(int num_arrays, int* sizes, int** values) {

  // Finding the size of the values array
  int sizeOfValues = 0;
  for (int i = 0; i < num_arrays; i++) {
    sizeOfValues = sizeOfValues + sizes[i];
  }

  int* dupResult = (int*) calloc(sizeOfValues, sizeof(int));

  // put all elements into a 1D array called dupResult (contains duplicate elements)
  flattenArrayOfArrays(num_arrays, sizes, values, dupResult);

  // sort the result containing duplicates
  mergesort(sizeOfValues, dupResult);

  // removes the duplicates with the size in result[0] followed by the elements
  int* result = removeDuplicates(dupResult, sizeOfValues);

  free(dupResult);
  return result;
}

int* removeDuplicates(int* array, int size) {

  // determine size of deduped array
  // start numUniqueValues at 1 since we're assuming the first value to be
  // unique.
  int i;
  int numUniqueValues = 0;
  for(i = 0; i < size; i++) {
    if (array[i] != array[i+1]) {
      numUniqueValues++;
    }
  }

  int* result = (int*) calloc(numUniqueValues + 1, sizeof(int));

  // The first element in result is going to be the number of values that precede it
  result[0] = numUniqueValues;

  // start resultIndex to account for the size value
  int resultIndex = 1;

  // Remove duplicates from the given array and put it in the results array
  int j;
  for(j = 0; j < size; j++) {
    if (array[j] != array[j+1]) {
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
