#include <bits/stdc++.h>

using namespace std;

// helper function for get digital portion of a string
string Digitalize(string& a){
    int i = 0;
    int size = a.size();
    while(i<size && (a[i]<'0'||a[i]>'9')){
        ++i;
    }
    auto result = string(a,i);
    if(!result.size()){
        cout << "invalid input data" << endl;
        exit(0);
    }
    return result;
}

// Comparator for large number especially String
// a<=b -> false
// a>b -> true
template<typename T>
bool cmp(T& a,T& b){
    return a > b;
}

template<>
bool cmp<string>(string& a,string& b){
    if(!a.size()||!b.size()){
        cout << "invalid input data" << endl;
        exit(0);
    }
    bool signA = a[0]!='-';
    bool signB = b[0]!='-';
    if(!signA&&signB){
        // a<0,b>0 -> a<b
        return false;
    }else if(signA&&!signB){
        // a>0,b<0 -> a>b
        return true;
    }
    // a,b are same sign
    string digitA = Digitalize(a);
    string digitB = Digitalize(b);
    int endA = digitA.size()-1;
    int endB = digitB.size()-1;
    bool isGreater = false;
    bool isEqual = false;
    // same length
    if(endA==endB){
        for(int i=0;i<=endA;++i){
            if(digitA[i]!=digitB[i]){
                isGreater = digitA[i]>digitB[i];
                break;
            }
            if(i==endA&&digitA[i]==digitB[i]){
                isEqual = true;
            }
        }
    }
    if(signA){
        return endA>endB||isGreater;
    }else{
        return endA<endB||!isGreater&&!isEqual;
    }
}

// helper function for print to check the correctness
template<typename T>
void Print(vector<T>& arr,int size){
    for(int i=0;i<size-1;++i){
        cout << arr[i] << ",";
    }
    cout << arr[size-1] << endl;
}

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

// helper function to compare 2 arrays
// return true if they are the same
bool Check(vector<int>& arr1,vector<int>& arr2){
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
    for(int i=0;i<1000;++i){
        vector<int> temp = RandomArray();
        if(!TestBubbleSortHelper(temp)){
            cout << "BubbleSort正确性检测不通过" << endl;
        }
    }
    cout << "BubbleSort正确性检测通过" << endl;
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
    for(int i=0;i<1000;++i){
        vector<int> temp = RandomArray();
        if(!TestSelectionSortHelper(temp)){
            cout << "SelectionSort正确性检测不通过" << endl;
        }
    }
    cout << "SelectionSort正确性检测通过" << endl;
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
    for(int i=0;i<1000;++i){
        vector<int> temp = RandomArray();
        if(!testMergeSortHelper(temp)){
            cout << "MergeSort正确性检测不通过" << endl;
        }
    }
    cout << "MergeSort正确性检测通过" << endl;
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
