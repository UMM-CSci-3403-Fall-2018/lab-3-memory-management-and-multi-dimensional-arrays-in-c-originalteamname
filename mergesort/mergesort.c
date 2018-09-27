#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mergesort.h"

void mergesort(int size, int *values) {
  mergesortRange(size, values, 0, size - 1);
}

void mergesortRange(int size, int *values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex) / 2;
    mergesortRange(size, values, startIndex, midPoint);
    mergesortRange(size, values, midPoint, endIndex);
    mergeRanges(size, values, startIndex, midPoint, endIndex);
  }
}

void mergeRanges(int size, int *values, int startIndex, int midPoint, int endIndex) {
  final int = rangeSize = endIndex - startIndex;
  int destination[rangeSize];
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;

  while((firstIndex < midPoint) && (secondIndex < endIndex)) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }

  while(firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }

  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }

  for(int i = 0; i < rangeSize; i++) {
    values[i + startIndex] = destination[i];
  }
}

bool needsSorting(int rangeSize) {
  return rangeSize >= 2;
}
