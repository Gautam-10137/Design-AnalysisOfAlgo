#include<iostream>
using namespace std;
void insertion(int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int temp = arr2[i];
        while (j >= 0 && arr2[j] > temp)
        {
            arr2[j + 1] = arr2[j];
            j--;
        }
        arr2[j + 1] = temp;
    }
}
int main(){
    int n;
    cout<<"Insertion sort"<<endl;
    cout<<"Enter the numbr of values"<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion(arr,n);
    cout<<"Elements in sorted order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
