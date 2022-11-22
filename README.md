# 北航程序设计与算法课程大作业——大数排序算法
 这是由葛宇飞、王永鑫、张亚奇完成的北京航空航天大学周号益老师所教课程《程序设计与算法》布置的大作业——大数排序算法。
 该作业要求基于C或C++语言，实现[选择、归并、快速、希尔、基数]五种排序算法，对数值范围在[-10^100-10^100]的数组进行排序，并对所有算法进行分析在不同规模的输入下单机性能的变化情况。

# 算法简介

## 使用方法
* 所有排序算法的实现都在sort.h头文件中，每种排序算法输入均为vector<T>& arr；
* 在test.h中实现了随机数据的生成，以及对每种排序算法正确性验证和时间性能的分析；
* 在main.cpp文件中直接调用相应的TestSort即可自动完成统一随机数的生成，然后对每种算法进行正确性验证，最后统一对比每种算法的时间开销。

## 公共方法 

### 数值类型转换函数——string Digitalize(string& a)
此方法主要是获取随机生成的string类型数据的数值化表示    
``` c++
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
```
### 比较函数——bool cmp<string>(string& a,string& b)
此方法用于比较两个带符号的数之间的大小。  
根据输入数据的符号进行判断大小，如果异号则可直接返回结果，否则去掉符号位后逐位进行比较。  
如果a > b则返回false，否则返回true。
``` c++
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
```
### 打印调试函数——void Print(vector<T>& arr,int size)
此方法主要用于调试程序时逐位打印输出数据使用
``` c++
template<typename T>
void Print(vector<T>& arr,int size){
    for(int i=0;i<size-1;++i){
        cout << arr[i] << ",";
    }
    cout << arr[size-1] << endl;
}
```

## 测试验证方法
### 随机数据生成函数——vector<string> RandomStringArray()
此方法主要用于测试阶段随机数据的生成。  
数据范围为10^30 ，string类型带有正负号
``` c++
template<>
vector<string> RandomArray<string>(){
    srand(time(NULL));
    int size = rand()%50000+1;
    vector<string> arr(size,"");
    for(int i=0;i<size;++i){
        bool sign = rand()%2;
        arr[i] = (sign ? "+" : "-" ) + to_string(rand()%5000);
        for ( int j = 0; j < 5; j++){
            arr[i] += to_string(rand()%5000);
        }
    }
    return arr;
}
```
### 检查数据相等函数——bool Check(vector<T>& arr1,vector<T>& arr2)
此方法主要用于检查两个数是否相等。  
如果两数长度不等则直接返回false，否则按位对比是否相等。
``` c++
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
```

### 测试排序算法函数——void TestSort()
以下以选择排序举例
此方法主要用于判断算法的正确性。  
先进行一千论测试，每轮测试中随机生成数据然后进行排序，如果此轮测不通过则跳出循环。  
最后根据通过的轮数给出此算法正确性结果。
``` c++
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
```
### 测试排序算法辅助函数——bool TestSortHelper(vector<int>& arr)
以下以选择排序举例
此方法主要用于进行判断此算法在某一轮排序中结果是否正确。  
``` c++
bool TestSelectionSortHelper(vector<int>& arr){
    vector<int> temp = arr;
    SelectionSort(temp);
    sort(arr.begin(),arr.end());
    return Check(arr,temp);
}
```
## 排序算法实现
***
### **选择排序**
#### 算法简介
每一趟从待排序的数据元素中选择最小（或最大）的一个元素作为首元素，直到所有元素排完为止。
#### 算法实现
``` c++
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
```
#### 时间复杂度分析
##### 理论分析
* 最好情况：所有元素按照从小到大（或从大到小）已经排好序 O(n2)
* 最坏情况：所有元素按照从大到小（或从小到大）逆序排列 O(n2)
* 平均情况：O(n2)
##### 单机性能变化
#### 空间复杂度分析
##### 理论分析
* 选择排序不需要额外的存储空间 o(1)

***
### **归并排序**
#### 算法简介
#### 算法实现
``` c++

```
#### 时间复杂度分析
##### 理论分析
##### 单机性能变化
#### 空间复杂度分析
##### 理论分析
##### 单机性能变化
***
### **快速排序**
#### 算法简介
#### 算法实现
``` c++

```
#### 时间复杂度分析
##### 理论分析
##### 单机性能变化
#### 空间复杂度分析
##### 理论分析
##### 单机性能变化
***
### **希尔排序**
#### 算法简介
#### 算法实现
``` c++

```
#### 时间复杂度分析
##### 理论分析
##### 单机性能变化
#### 空间复杂度分析
##### 理论分析
##### 单机性能变化
***
### **基数排序**
#### 算法简介
#### 算法实现
``` c++

```
#### 时间复杂度分析
##### 理论分析
##### 单机性能变化
#### 空间复杂度分析
##### 理论分析
##### 单机性能变化

### 算法之间的比较

# 总结
## 学习与收获
## 面临的一些挑战和还未实现的功能
## 致谢







