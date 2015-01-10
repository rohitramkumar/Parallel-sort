/**
 * @file psort.h
 */

#ifndef _PSORT_H_
#define _PSORT_H_

#include <iostream>
#include <vector>
#include <omp.h>

using std::vector;

namespace ParallelSort
{
    /**
     * Public wrapper for the parallel sort implementation.
     * @param array - The structure to sort
     */
    template <class T>
    void psort(vector<T>* array);
    
    /**
     * Function that is called by the concurrent_sort function if the number of elements to sort is less than 50.
	 * @param array - The structure to sort
	 * @param lo - represents the low index of a particular section of the array
	 * @param high - represents the high index of a particular section of the array
     */
    template<class T>
    void sequential_psort(vector<T>* array, int lo, int high);

    /**
     * Function that is called by wrapper to execute a parallel quicksort	
	 * @param array - The structure to sort
	 * @param lo - represents the low index of a particular section of the array
	 * @param high - represents the high index of a particular section of the array
     */
    template<class T>
    void concurrent_psort(vector<T>* array, int lo, int high);

    /**
     * Helper function that partitions vector based on a pivot value	
	 * @param array - The structure to partition
	 * @param lo - represents the low index of a particular section of the array
	 * @param high - represents the high index of a particular section of the array
	 * @return int - index of the pivot value
     */
    template <class T>
    int partition(vector<T>* array, int lo, int high);
    
    /**
     * Helper function that produces a random pivot index	
	 * @param lo - represents the low index of a particular section of the array
	 * @param high - represents the high index of a particular section of the array
	 * @return int - the index of the random pivot
     */
    int getRandomPivot(int lo, int high);

    /**
     * Function that performs an insertion sort
	 * @param array - the structure to sort
     * @param lo - value to keep track of the low bound of structure during sorting
	 * @param hi - value to keep track of the high bound of structure during sorting
     */
    template<class T>
    void insertionSort(vector<T>* array, int lo, int hi);

    /**
     * Function that checks if the array is already sortedi
	 * @param array - the structure that we want to check 
	 * @return bool - whether the structure is sorted or not
     */ 
     template <class T>
    bool sorted(vector<T>* array);

    /**
     * Helper function that swaps two indices in the given vector.
	 * @param array - the structure that holds the indices we are swapping
     * @param index1 - index of the first element we want to swap
     * @param index2 - index of the second element we want to swap
     */
    template <class T>
    void swap(vector<T>* array, int index1, int index2);
}

#include "psort.cpp"
#endif
