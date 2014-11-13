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
     * @param array The structure to sort
     */
    template <class T>
    void psort(vector<T>* array);
    
    /**
     * Function that is called by wrapper if the number of elements to sort is less than 50.
     */
    template<class T>
    void sequential_qsort(vector<T>* array, int lo, int high);

    /**
     * Function that is called by wrapper to execute a parallel quicksort
     */
    template<class T>
    void parallel_qsort(vector<T>* array, int lo, int high);


    /**
     * Helper function that partitions vector based on a pivot value
     */
    template <class T>
    int partition(vector<T>* array, int lo, int high);
    
    /**
     * Helper function that produces a random pivot index
     */
    int getRandomPivot(int lo, int high);

    /**
     * Function that performs an insertion sort
     */
    template<class T>
    void insertionSort(vector<T>* array, int lo, int hi);


    /**
     * Helper function that swaps two indeces in the given vector.
     */
    template <class T>
    void swap(vector<T>* array, int index1, int index2);


}

#include "psort.cpp"
#endif
