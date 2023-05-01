#include<bits/stdc++.h>
using namespace std;
vector<int>pivotA;
int partition(int*arr,int si,int ei){
    
    int idx=(rand() % (ei - si + 1)) + si ;
    int pivot=si;
    for(int i=si;i<=ei;i++){
        if(arr[i]<arr[idx]){
            pivot++;
        }
    }
    pivotA.push_back(arr[idx]);
    swap(arr[pivot],arr[idx]);
    int i=0,j=pivot+1;
    while(i<pivot&&j<=ei){
        if(arr[i]<arr[pivot]){
            i++;
        }
        else if(arr[j]>arr[pivot]){
            j++;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j++;
        }

    }

    return pivot;
    
}
void quick(int* arr,int si,int ei){
    if(si>ei) return;
    int pivot=partition(arr,si,ei);
    quick(arr,si,pivot-1);
    quick(arr,pivot+1,ei);
}

int main(){
   int n;
   cout<<"Enter the number of data"<<endl;
   cin>>n;
   int *arr=new int[n];
   for(int i=0;i<n;i++){
    arr[i]=1+(rand()%100);
   }
   cout<<"Input the data"<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   quick(arr,0,n-1);
   cout<<"data in sorted order"<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"pivot elements"<<endl;
   for(int i=0;i<pivotA.size();i++){
    cout<<pivotA[i]<<" ";
   }
   return 0;
}