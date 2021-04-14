#include <cstdlib>
#include <iostream>


using namespace std;

template<class T>
void make2dArray(T ** &array, const int& numberOfRows, const int& numberOfColumns){

  array = new T * [numberOfRows];

  for (int i = 0; i < numberOfColumns; ++i){
    array[i] = new T [numberOfColumns];
  }
}

template<class T>
void delete2dArray(T ** &array, const int& numberOfRows){

  for (int i = 0; i < numberOfRows; ++i){
    delete [] array[i];
  }

  delete [] array;
  array = NULL;
}

int main(void) {
  int **array;
  int numberOfRows = 5;
  int numberOfColumns = 5;

  make2dArray(array, numberOfRows, numberOfColumns);
  for (int i = 0; i < numberOfRows; ++i) {
    for (int j = 0; j < numberOfColumns; ++j) {
      array[i][j] = i * 2 + j * 3;
    }
  }

  cout << array << endl;

  delete2dArray(array, numberOfRows);

  return 0;
}
