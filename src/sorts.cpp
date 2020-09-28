#include "../include/sorts.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void changeIndexValues(int *array, int i, int j) {
  int aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

void insertSort(int *array, int arrayLength) {
  for (int i = 0; i < arrayLength - 1; i++) {
    int min = i;

    for (int j = i + 1; j < arrayLength; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    changeIndexValues(array, i, min);
  }
}

void selectionSort(int *array, int arrayLength) {
  for (int j = 1; j < arrayLength; j++) {
    int pivot = array[j];
    int i = j - 1;

    while (i >= 0 && array[i] > pivot) {
      array[i + 1] = array[i];
      i = i - 1;
    }

    array[i + 1] = pivot;
  }
}

void merge(int *array, int first, int middle, int last) {
  int index1 = first;
  int index2 = middle;
  int i = 0;
  int *arrayOrdered = new int[last];

  while ((index1 < middle) && (index2 < last)) {
    if (array[index1] < array[index2]) {
      arrayOrdered[i] = array[index1];
      index1++;
    } else {
      arrayOrdered[i] = array[index2];
      index2++;
    }
    i++;
  }

  while (index1 < middle) {
    arrayOrdered[i] = array[index1];
    i++;
    index1++;
  }
  while (index2 < last) {
    arrayOrdered[i] = array[index1];
    i++;
    index2++;
  }

  for (int j = first; j < last; j++) {
    array[j] = arrayOrdered[j - first];
  }
}

void mergeSort(int *array, int first, int last) {
  if (first < last - 1) {
    int middle = (first + last) / 2;
    mergeSort(array, first, middle);
    mergeSort(array, middle, last);
    merge(array, first, middle, last);
  }
}
