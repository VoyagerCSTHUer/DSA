#include "MyMergeSort.h"

LineOrPoint::LineOrPoint(int a,int b):x(a),y(b){}

int LineOrPoint::cross_with(LineOrPoint line){
    if(static_cast<float>(this->x)/static_cast<float>(line.x) +
         static_cast<float>(this->y)/static_cast<float>(line.y) >= 1.0){
            return 1;
        }
        return 0;
}

int LinearSearch(LineOrPoint* s,int s_size,LineOrPoint p){
    int sum = 0;
    for(int i=0;i<s_size;i++){
        sum += p.cross_with(s[i]);
    }
    return sum;
}

void combine(int* a,int* b,int a_size,int b_size){
    int* result = new int[a_size+b_size];
    int i=0;
    int j=0;
    int cnt = 0;
    while (i<a_size && j<b_size){
        if(a[i]<=b[j]){
            result[cnt] = a[i];
            i++;
        }
        else{
            result[cnt] = b[j];
            j++;
        }
        cnt++;
    }
    if(i == a_size){
        for(int k=j;k<b_size;k++){
            result[cnt] = b[k];
            cnt++;
        }
    }
    else if(j == b_size){
        for(int k=i;k<a_size;k++){
            result[cnt] = a[k];
            cnt++;
        }
    }
    for(int i=0;i<a_size;i++) a[i] = result[i];
    for(int j=0;j<b_size;j++) b[j] = result[a_size+j];
    return;
}

void MergeSort(int* a,int a_size){
    if(a_size < 2){
        return;
    }
    else{
        int mid = a_size/2;
        MergeSort(a,mid);
        MergeSort(a+mid,a_size-mid);
        combine(a,a+mid,mid,a_size-mid);
    }
}
