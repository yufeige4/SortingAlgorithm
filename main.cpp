#include "test.h"

// explicit instantiation
template bool cmp<string>(string& a,string& b);
template void Print<int>(vector<int>& arr,int size);
template void BubbleSortHelper<int>(vector<int>& arr,int size);
template void BubbleSort<int>(vector<int>& arr);
template void Merge<int>(vector<int>& arr,int i,int j,int k);
template void MergeSortHelper<int>(vector<int>& arr,int start,int end);
template void MergeSort<int>(vector<int>& arr);
template void BubbleSortHelper<string>(vector<string>& arr,int size);
template void BubbleSort<string>(vector<string>& arr);
template void Merge<string>(vector<string>& arr,int i,int j,int k);
template void MergeSortHelper<string>(vector<string>& arr,int start,int end);
template void MergeSort<string>(vector<string>& arr);

int main(){
    // 随机生成1000个数组，数组大小为随机1至5000，数组元素为随机0至4999的int数据
    // 先分别测试其的正确性

    TestSelectionSort();
    TestMergeSort();
    TestShellSort();
    TestQuickSort();
    TestRadixSort();
    
    // 再随机生成1000个数组，数组大小为随机1至50000，数组元素为随机0至10^30的string数据
    // 拷贝相同的数据集
    // 使用选择排序, 归并排序, 快速排序, 希尔排序和基数排序分别对于其中一个完全相同数据集进行排序
    // 记录下他们所花费的时间并比较
    // CompareAlgorithms();

    return 0;
};
 