#include <iostream>
#include <chrono>
#include <cstdlib>
#include<climits>
using namespace std::chrono;
using namespace std;

void copy(int *arr1, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }
}
int insertion(int *arr, int n)
{
    auto start = high_resolution_clock::now();
    // coping from original array
    cout << "Insertion sort" << endl;
    cout << "Input data" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int arr2[n] = {0};
    copy(arr, arr2, n);
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
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Insertion sort takes " << duration.count() << " millisecond" << endl;    
    cout << "output data" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return duration.count();
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int bubble(int *arr, int n)
{
    auto start = high_resolution_clock::now();
    cout << "bubble sort" << endl;
    cout << "Input data" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int arr2[n] = {0};
    copy(arr, arr2, n);
    int i = n - 1;
    while (i >= 0)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                swap(arr2[j], arr2[j + 1]);
            }
        }
        i--;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Bubble sort takes " << duration.count() << "milliseconds" << endl;   
    cout << "output data" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return duration.count();
}
void countSort(int* arr,int n){
        auto start = high_resolution_clock::now();
    int maxE=INT_MIN;
    for(int i=0;i<n;i++){
        maxE=max(maxE,arr[i]);
    }
    int* freq=(int*)calloc(maxE+1, sizeof(int));
    int* output=(int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=1;i<maxE+1;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[--freq[arr[i]]]=arr[i];
    }
    cout<<"count Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "counting sort takes " << duration.count() << "milliseconds" << endl;  
  
}

int main()
{
    int it;
    cout<<"Enter number of iterations"<<endl;
    cin>>it;
    int res1[it][2]={};
    int res2[it][2]={};
    int iteration=0;
 while(iteration<it){   
    int n;
    cout<<"Enter input size of data"<<endl;
    cin >> n;
    int *arr;
    
    if(n<=20){
        cout<<"Enter the values of data"<<endl;
        arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    else{
    arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + (rand() % 100);
    }
    }
    countSort(arr,n);
    int time1=insertion(arr, n);
    res1[iteration][0]=n;
    res1[iteration][1]=time1;
    int time2=bubble(arr, n);
    res2[iteration][0]=n;
    res2[iteration][1]=time2;
    delete arr;
    iteration++;
    }
    cout<<"Insertion sort values:-"<<endl;
    cout<<"Input size"<<"   "<<"time"<<endl;
    for(int i=0;i<it;i++){
        cout<<"  "<<res1[i][0]<<"         ";
        cout<<res1[i][1]<<endl;
    }
    cout<<"Bubblesort values:-"<<endl;
    cout<<"Input size"<<"   "<<"time"<<endl;
    for(int i=0;i<it;i++){
        cout<<"  "<<res2[i][0]<<"         ";
        cout<<res2[i][1]<<endl;
    }
    return 0;
}
