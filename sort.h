/**
 * header file for sorting algorithm implements
*/
#ifndef HEADER_BITS
#define HEADER_BITS
#include <bits/stdc++.h>
#endif
#include "common.h"

using namespace std;

// bubble sort O(n^2)
template<typename T>
void BubbleSortHelper(vector<T>& arr,int size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size-i-1;++j){
            if(cmp<T>(arr[j],arr[j+1])){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// wrapper function for BubbleSort Algorithm
template<typename T>
void BubbleSort(vector<T>& arr){
    BubbleSortHelper<T>(arr,arr.size());
}

// selection sort O(n^2)
template<typename T>
void SelectionSortHelper(vector<T>& arr,int size){
    for(int i=0;i<size;++i){
        T smallest = arr[i];
        int index = i;
        for(int j=i+1;j<size;++j){
            if(cmp<T>(smallest,arr[j])){
                smallest = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
} 

// wrapper function for BubbleSort Algorithm
template<typename T>
void SelectionSort(vector<T>& arr){
    SelectionSortHelper<T>(arr,arr.size());
}

// helper function for MergeSort
// merge from index [i,j] to [j+1,k]
template<typename T>
void Merge(vector<T>& arr,int i,int j,int k){
    int size = k-i+1;
    T temp[size];
    int index = 0;
    int left = i;
    int right = j+1;
    while(left<=j||right<=k){
        if(left>j){
            temp[index++] = arr[right++];
        }else if(right>k){
            temp[index++] = arr[left++];
        }else{
            if(cmp<T>(arr[right],arr[left])){
                temp[index++] = arr[left++];
            }else{
                temp[index++] = arr[right++];
            }
        }
    }
    for(int cnt=0;cnt<size;++cnt){
        arr[cnt+i] = temp[cnt];
    }
}

// merge sort O(nlogn)
template<typename T>
void MergeSortHelper(vector<T>& arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2; // take care of overflow issue
    MergeSortHelper<int>(arr,start,mid);
    MergeSortHelper<int>(arr,mid+1,end);
    Merge<int>(arr,start,mid,end);
}

// wrapper function for MergeSort algorithm
template<typename T>
void MergeSort(vector<T>& arr){
    MergeSortHelper<T>(arr,0,arr.size()-1);
}

// Shell sort O(nlogn)
template<typename T>
void ShellSortHelper(vector<T>& arr,int size){
    int i,j,flag,gap = size;
    T temp;
    while(gap > 1){
        gap = gap/2;
        do{
            flag = 0;
            for (i = 0; i < size-gap; ++i){
                j = i + gap;
                if(cmp<T>(arr[i],arr[j])){
                    swap(arr[i],arr[j]);
                    flag = 1;
                }
            }
            
        }while( flag != 0 );
    }
}

// wrapper function for ShellSort Algorithm
template<typename T>
void ShellSort(vector<T>& arr){
    ShellSortHelper<T>(arr,arr.size());
}

// Quick sort partition
template<typename T>
int partition(vector<T>& arr, int start, int end){
    int pivot = start, i = start, j = end+1;
    while(true){
        do i++;
        while( cmp(arr[pivot],arr[i]) && i <= end );
        // while( arr[i] <= arr[pivot] && i <= end );
        do j--;
        while( cmp(arr[j],arr[pivot]) && j > start );
        // while( arr[j] >= arr[pivot] && j > start );
        if(i < j){
            swap(arr[i],arr[j]);
        }
        else{
            break;
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

// Quick sort O(nlogn)
template<typename T>
void QuickSortHelper(vector<T>& arr, int start, int end){
    if(start < end){
        int index = partition(arr, start, end);
        QuickSortHelper(arr, start, index-1);
        QuickSortHelper(arr, index+1, end);
    }
}

// wrapper function for QuickSort Algorithm
template<typename T>
void QuickSort(vector<T>& arr){
    QuickSortHelper<T>(arr,0,arr.size()-1);
}


// Helper function for RadixSort
void RadixSortHelper(vector<string>& arr){
    vector<queue<string>> buckets(10,queue<string>());
    vector<string> temp;
    int size = arr.size();
    int maxLen = 0;
    for(int i=0;i<size;++i){
        temp.push_back(arr[i]);
        maxLen = max(int(arr[i].size()),maxLen);
    }
    for(int i=0;i<maxLen;++i){
        for(int j=0;j<size;++j){
            int curr = temp[j].size()-i-1;
            if(curr<0){
                buckets[0].push(temp[j]);
                continue;
            }
            switch(temp[j][curr]){
                case '0':
                    buckets[0].push(temp[j]);
                    break;
                case '1':
                    buckets[1].push(temp[j]);
                    break;
                case '2':
                    buckets[2].push(temp[j]);
                    break;
                case '3':
                    buckets[3].push(temp[j]);
                    break;
                case '4':
                    buckets[4].push(temp[j]);
                    break;
                case '5':
                    buckets[5].push(temp[j]);
                    break;
                case '6':
                    buckets[6].push(temp[j]);
                    break;
                case '7':
                    buckets[7].push(temp[j]);
                    break;
                case '8':
                    buckets[8].push(temp[j]);
                    break;
                case '9':
                    buckets[9].push(temp[j]);
            }
        }
        temp.clear();
        for(int j=0;j<10;++j){
            auto& q = buckets[j];
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
        }
    }
    arr = temp;
}
// Radix Sort
void RadixSort(vector<string>& arr){
    vector<string> negatives;
    vector<string> positives;
    // seperate elements into 2 arrays by its sign
    for(auto& str : arr){
        if(str[0]=='-'){
            negatives.push_back(Digitalize(str));
        }else{
            positives.push_back(Digitalize(str));
        }
    }

    RadixSortHelper(negatives);
    RadixSortHelper(positives);
    // put them back to original array
    int count = 0;
    for(int i=negatives.size()-1;i>=0;--i){
        arr[count++] = negatives[i];
    }
    int size = positives.size();
    for(int i=0;i<size;++i){
        arr[count++] = positives[i];
    }
}