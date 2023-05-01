#include<iostream>
using namespace std;
void countSort(int* arr,int n,int k){
    int* freq=(int*)calloc(k+1, sizeof(int));
    int* output=(int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=1;i<k+1;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[--freq[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    delete []freq;
    delete[]output;

}
int main(){
    int n,k;
    cout<<"Enter number of values"<<endl;
    cin>>n;
    cout<<"Enter maximum element in your data(less than 11)"<<endl;
    cin>>k;
    int* arr=new int[n];

    for(int i=0;i<n;i++){
        int item;
        cout<<"Enter "<<i+1<<"th value"<<endl;
         cin>>item;
        while(item>k){
            cout<<"You have entered a value greater than range"<<endl;
            cout<<"Enter the value again"<<endl;
            cin>>item;
        }
        arr[i]=item;
    }
    cout<<"Values in sorted order"<<endl;
    countSort(arr,n,k);
    delete[]arr;
    return 0;
}