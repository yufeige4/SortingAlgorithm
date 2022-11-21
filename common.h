/**
 * header file for common functions
*/
#ifndef HEADER_BITS
#define HEADER_BITS
#include <bits/stdc++.h>
#endif

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