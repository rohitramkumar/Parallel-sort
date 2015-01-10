/**
 * @file psort.cpp
 *
 */

#include <stdlib.h>
#include <iostream>

template <class T>
void ParallelSort::psort(vector<T>* array)
{
    omp_set_num_threads(16);
    omp_set_nested(0);
    #pragma omp parallel
    #pragma omp single nowait
    concurrent_psort(array, 0, array -> size() - 1);

}

template<class T>
bool ParallelSort::sorted(vector<T>* array) {

    bool isSorted = true;
    for(int i = 0; i < array -> size() - 1; i++) {
	if(array -> at(i) > array -> at(i+1)) return false;
    }
    return true;
}

template <class T>
void ParallelSort::concurrent_psort(vector<T>* array, int lo, int high) {
    
    if(lo < high) {
      if(high - lo < 20) {
        insertionSort(array, lo, high);
      }
      if(high - lo < 250) {
        sequential_psort(array, lo, high);
      }
      else {
        int pivotIndex = partition(array, lo, high);

        #pragma omp task
        concurrent_psort(array, lo, pivotIndex - 1);
		#pragma omp task
        concurrent_psort(array, pivotIndex + 1, high);
      }
    }
}

template<class T>
void ParallelSort::sequential_psort(vector<T>* array, int lo, int high) {

  if(lo >= high) return;
  int pivotIndex = partition(array, lo, high);
  sequential_psort(array, lo, pivotIndex - 1);
  sequential_psort(array, pivotIndex + 1, high);

}

/**
* Adapted from: https://wiki.cites.illinois.edu/wiki/display/cs125/Sorting+Algorithms?src=search
*
*/
template <class T>
int ParallelSort::partition(vector<T>* array, int lo, int high) {
   
   int pivotIndex = lo + (high - lo) / 2;  
   T pivot = array -> at(pivotIndex);
   swap(array, lo, pivotIndex);
   int loRunner = lo + 1;
   int highRunner = high;
   while(loRunner < highRunner) {

        if(array -> at(loRunner) >= pivot) {
            swap(array, loRunner, highRunner);
            highRunner--;
        }
        else loRunner++;
   }

   int ret_val = 0;
   if(array -> at(loRunner) > pivot) ret_val = loRunner - 1;
   else ret_val = loRunner;

   swap(array, lo, ret_val);
   return ret_val;
       
}

template<class T>
void ParallelSort::insertionSort(vector<T>* array, int lo, int hi) {

  for(int i = lo + 1; i <= hi; i++) {
      int j = i - 1;
      int shiftingIndex = i;
      while(j > -1 && array -> at(shiftingIndex) < array -> at(j)) {
          swap(array, shiftingIndex, j);
          j--;
          shiftingIndex--;
      }
  }       
}    


int ParallelSort::getRandomPivot(int lo, int high) {
    
    int size = high - lo + 1;
    if(size <= 5) return lo;
    else return (rand() % size) + lo;
    
}


template <class T>
void ParallelSort::swap(vector<T>* array, int index1, int index2) {
    
    if(index1 == index2) return;
    T temp = array -> at(index1);
    array -> at(index1) = array -> at(index2);
    array -> at(index2) = temp;
}

