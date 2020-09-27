#include "src/sorts.cpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int *generateRandomArray(int arrayLength) {
  int *array = new int[arrayLength];

  for (int i = 0; i < arrayLength; i++) {
    int randomNumber = rand() % (arrayLength + 50);
    array[i] = randomNumber;
  }

  return array;
}

int *generateArrayCopy(int *array, int arrayLength) {
  int *arrayCopy = new int[arrayLength];
  for (int i = 0; i < arrayLength; i++) {
    arrayCopy[i] = array[i];
  }

  return arrayCopy;
}

void printArray(int *array, int arrayLength) {
  cout << endl << "[";
  for (int i = 0; i < arrayLength; i++) {
    cout << array[i];

    if (i != arrayLength - 1)
      cout << ",";
    else
      cout << "]" << endl;
  }
}

int main() {
  int arrayLength = 10;
  int *array = generateRandomArray(arrayLength);

  printArray(array, arrayLength);
  selectionSort(array, arrayLength);
  printArray(array, arrayLength);

  system("pause");
  return 0;
}
