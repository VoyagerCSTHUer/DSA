#include<iostream>
#include<MyMergeSort.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    LineOrPoint* lineset;
    lineset = new LineOrPoint[n];
    int *x_array = new int[n];
    int *y_array = new int[n];
    for(int i=0;i<n;i++){
        cin>>x_array[i];
    }
    for(int i=0;i<n;i++){
        cin>>y_array[i];
    }
    MergeSort(x_array,n);
    MergeSort(y_array,n);
    for(int i=0;i<n;i++){
        lineset[i].x = x_array[i];
        lineset[i].y = y_array[i];
    }

    int m;
    cin>>m;
    LineOrPoint* aim;
    aim = new LineOrPoint[m];
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        aim[i] = LineOrPoint(t1,t2);
    }

    for(int i=0;i<m;i++){
        cout<<LinearSearch(lineset,n,aim[i])<<endl;
    }
    return 0;
}