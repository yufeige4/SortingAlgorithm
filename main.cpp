#include "code.h"


// explicit instantiation
template bool cmp<string>(string& a,string& b);
template void Print<int>(vector<int>& arr,int size);
template void BubbleSortHelper<int>(vector<int>& arr,int size);
template void BubbleSort<int>(vector<int>& arr);
template void Merge<int>(vector<int>& arr,int i,int j,int k);
template void MergeSortHelper<int>(vector<int>& arr,int start,int end);
template void MergeSort<int>(vector<int>& arr);

int main(){
    // 随机生成1000个数组，数组大小为随机1至5000，数组元素为随机0至4999的int数据
    // 先分别测试其的正确性
    time_t timeStart;
    time_t timeEnd;
    time(&timeStart);
    TestBubbleSort();
    TestSelectionSort();
    TestMergeSort();
    TestShellSort();
    TestQuickSort();
    TestRadixSort();
    time(&timeEnd);
    cout << "total time: " << timeEnd - timeStart << endl;
    
    // 再随机生成10000个数组，数组大小为随机1至5000，数组元素为随机0至4999的int数据
    // 拷贝一份相同的数据集
    // 使用冒泡排序和归并排序分别对于其中一个完全相同数据集进行排序
    // 记录下他们所花费的时间并比较
    // CompareTwoAlgorithm();

    return 0;
};
