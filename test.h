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
vector<int> RandomArray(){
    srand(time(NULL));
    int size = rand()%5000+1;
    vector<int> arr(size,0);
    for(int i=0;i<size;++i){
        arr[i] = rand()%5000;
    }
    return arr;
}

// helper function to randomly generate string array
vector<string> RandomStringArray(){
    srand(time(NULL));
    int size = rand()%5000+1;
    vector<string> arr(size,0);
    for(int i=0;i<size;++i){
        arr[i] = to_string(rand()%5000);
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
        vector<int> temp = RandomArray();
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
        vector<int> temp = RandomArray();
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
        vector<int> temp = RandomArray();
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
        vector<int> temp = RandomArray();
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
        vector<int> temp = RandomArray();
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
        vector<int> temp = RandomArray();
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
void CompareTwoAlgorithm(){
    vector<vector<int>> sampleArrays;
    // randomly generate 1000 arrays, stored in sampleArrays
    for(int i=0;i<10000;++i){
        vector<int> temp = RandomArray();
        sampleArrays.push_back(temp);
    }
    vector<vector<int>> copiedArrays = sampleArrays;

    time_t startTimeBubbleSort;
    time_t endTimeBubbleSort;
    time_t startTimeMergeSort;
    time_t endTimeMergeSort;

    // use both algorithms to the same data set seperately
    // and recored their start time and end time
    time(&startTimeBubbleSort);
    for(int i=0;i<10000;++i){
        BubbleSort(sampleArrays[i]);
    }
    time(&endTimeBubbleSort);

    time(&startTimeMergeSort);
    for(int i=0;i<10000;++i){
        MergeSort(copiedArrays[i]);
    }
    time(&endTimeMergeSort);
    time_t BubbleSortCost = difftime(endTimeBubbleSort,startTimeBubbleSort);
    time_t MergeSortCost = difftime(endTimeMergeSort,startTimeMergeSort);
    cout << "对于10000组相同数据，BubbleSort时间为" << BubbleSortCost << endl;
    cout << "对于10000组相同数据，MergeSort时间为" << MergeSortCost << endl;
}