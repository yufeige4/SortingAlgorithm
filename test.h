/**
 * header file for test sorting algorithm
*/
#ifndef HEADER_BITS
#define HEADER_BITS
#include <bits/stdc++.h>
#endif
#include "sort.h"

using namespace std;

// helper function to randomly generate int array
template<typename T>
vector<T> RandomArray(){
    srand(time(NULL));
    int size = rand()%5000+1;
    vector<T> arr(size,0);
    for(int i=0;i<size;++i){
        arr[i] = rand()%5000;
    }
    return arr;
}

// helper function to randomly generate long string array
template<>
vector<string> RandomArray<string>(){
    srand(time(NULL));
    int size = rand()%50000+1;
    vector<string> arr(size,"");
    for(int i=0;i<size;++i){
        arr[i] = to_string(rand()%5000);
        for ( int j = 0; j < 5; j++){
            arr[i] += to_string(rand()%5000);
        }
    }
    return arr;
}

// helper function to compare 2 arrays
// return true if they are the same
template<typename T>
bool Check(vector<T>& arr1,vector<T>& arr2){
    int size1 = arr1.size();
    int size2 = arr2.size();
    if(size1!=size2){
        return false;
    }
    for(int i=0;i<size1;++i){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}

// helper function to test the correctness of BubbleSort algorithm
// return false for incorrect result
bool TestBubbleSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    BubbleSort(temp);
    sort(arr.begin(),arr.end());
    return Check(arr,temp);
}

// randomly generate 1000 arrays to test the correctness of BubbleSort algorithm
void TestBubbleSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!TestBubbleSortHelper(temp)){
            break;
        }
    }
    if(i == 1000)
        cout << "BubbleSort正确性检测通过" << endl;
    else
        cout << "BubbleSort正确性检测不通过" << endl;
}

// helper function to test the correctness of SelectionSort algorithm
// return false for incorrect result
bool TestSelectionSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    SelectionSort(temp);
    sort(arr.begin(),arr.end());
    return Check(arr,temp);
}

// randomly generate 1000 arrays to test the correctness of SelectionSort algorithm
void TestSelectionSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!TestSelectionSortHelper(temp)){
            break;
        }
    }
    if(i == 1000)
        cout << "SelectionSort正确性检测通过" << endl;
    else
        cout << "SelectionSort正确性检测不通过" << endl;
}

// helper function to test the correctness of MergeSort algorithm
// return false for incorrect result
bool testMergeSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    MergeSort(arr);
    sort(temp.begin(),temp.end());
    return Check(arr,temp);
}

// randomly generate 1000 arrays to test the correctness of MergeSort algorithm
void TestMergeSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!testMergeSortHelper(temp)){
            break;
        }
    }
    if(i == 1000)
        cout << "MergeSort正确性检测通过" << endl;
    else
        cout << "MergeSort正确性检测不通过" << endl;
}

// helper function to test the correctness of ShellSort algorithm
// return false for incorrect result
bool testShellSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    ShellSort(arr);
    sort(temp.begin(),temp.end());
    return Check(arr,temp);
}

// randomly generate 1000 arrays to test the correctness of ShellSort algorithm
void TestShellSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!testShellSortHelper(temp)){
            break;
        }
    }
    if(i == 1000)
        cout << "ShellSort正确性检测通过" << endl;
    else
        cout << "ShellSort正确性检测不通过" << endl;
}

// helper function to test the correctness of QuickSort algorithm
// return false for incorrect result
bool testQuickSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    QuickSort(arr);
    sort(temp.begin(),temp.end());
    return Check(arr,temp);
}

// randomly generate 1000 arrays to test the correctness of QuickSort algorithm
void TestQuickSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!testQuickSortHelper(temp)){
           break;
        }
    }
    if(i == 1000)
        cout << "QuickSort正确性检测通过" << endl;
    else
        cout << "QuickSort正确性检测不通过" << endl;
}

// helper function to test the correctness of RadixSort algorithm
// return false for incorrect result
// 待修改
bool TestRadixSortHelper(vector<int>& arr){
    int size = arr.size();
    vector<string> temp(size,"");
    for(int i=0;i<size;++i){
        temp[i] = to_string(arr[i]);
    }
    RadixSort(temp);
    sort(arr.begin(),arr.end());
    vector<string> correct(size,"");
    for(int i=0;i<size;++i){
        correct[i] = to_string(arr[i]);
    }
    return Check<string>(correct,temp);
}

// randomly generate 1000 arrays to test the correctness of BubbleSort algorithm
void TestRadixSort(){
    int i;
    for(i=0;i<1000;++i){
        vector<int> temp = RandomArray<int>();
        if(!TestRadixSortHelper(temp)){
            break;
        }
    }
    if(i == 1000)
        cout << "RadixSort正确性检测通过" << endl;
    else
        cout << "RadixSort正确性检测不通过" << endl;
}

// randomly generate 1000 arrays and use both algorithms to sort them
// calculate the total time cost and compare them
void CompareAlgorithms(){
    vector<vector<string>> sampleArrays;
    // randomly generate 10 arrays, stored in sampleArrays
    for(int i=0;i<1000;++i){
        vector<string> temp = RandomArray<string>();
        sampleArrays.push_back(temp);
    }
    vector<vector<string>> copiedArrays1 = sampleArrays;
    vector<vector<string>> copiedArrays2 = sampleArrays;
    vector<vector<string>> copiedArrays3 = sampleArrays;
    vector<vector<string>> copiedArrays4 = sampleArrays;
    vector<vector<string>> copiedArrays5 = sampleArrays;

    time_t startTimeSelectionSort;
    time_t endTimeSelectionSort;
    time_t startTimeMergeSort;
    time_t endTimeMergeSort;
    time_t startTimeQuickSort;
    time_t endTimeQuickSort;
    time_t startTimeShellSort;
    time_t endTimeShellSort;
    time_t startTimeRadixSort;
    time_t endTimeRadixSort;

    // use both algorithms to the same data set seperately
    // and recored their start time and end time
    time(&startTimeSelectionSort);
    for(int i=0;i<1000;++i){
        SelectionSort<string>(copiedArrays1[i]);
    }
    time(&endTimeSelectionSort);

    time(&startTimeMergeSort);
    for(int i=0;i<1000;++i){
        MergeSort<string>(copiedArrays2[i]);
    }
    time(&endTimeMergeSort);

    time(&startTimeQuickSort);
    for(int i=0;i<1000;++i){
        MergeSort<string>(copiedArrays3[i]);
    }
    time(&endTimeQuickSort);

    time(&startTimeShellSort);
    for(int i=0;i<1000;++i){
        MergeSort<string>(copiedArrays4[i]);
    }
    time(&endTimeShellSort);

    time(&startTimeRadixSort);
    for(int i=0;i<1000;++i){
        MergeSort<string>(copiedArrays5[i]);
    }
    time(&endTimeRadixSort);

    time_t SelectionSortCost = difftime(endTimeSelectionSort,startTimeSelectionSort);
    time_t MergeSortCost = difftime(endTimeMergeSort,startTimeMergeSort);
    time_t QuickSortCost = difftime(endTimeQuickSort,startTimeQuickSort);
    time_t ShellSortCost = difftime(endTimeShellSort,startTimeShellSort);
    time_t RadixSortCost = difftime(endTimeRadixSort,startTimeRadixSort);
    cout << "对于1000组相同数据，SelectionSort时间为" << SelectionSortCost << endl;
    cout << "对于1000组相同数据，MergeSort时间为" << MergeSortCost << endl;
    cout << "对于1000组相同数据，QuickSort时间为" << QuickSortCost << endl;
    cout << "对于1000组相同数据，ShellSort时间为" << ShellSortCost << endl;
    cout << "对于1000组相同数据，RadixSort时间为" << RadixSortCost << endl;
}