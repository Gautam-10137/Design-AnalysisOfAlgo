#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
    return a.second.second<b.second.second;
}
int main(){
    int n;
    cout<<"Enter number of processes "<<endl;
    cin>>n;
    vector<pair<int,pair<int,int>>>task;
    for(int i=0;i<n;i++){
        int st,et;
        cout<<"Enter start time of process p"<<i+1<<"  ";
        cin>>st;
        cout<<"Enter end time of process p"<<i+1<<"   ";
        cin>>et;
        
        task.push_back(make_pair(i+1,make_pair(st,et)));
    }
    sort(task.begin(),task.end(),compare);
    
    int count=0;
    int time=0;
    vector<int>idx;
    for(int i=0;i<n;i++){
        if(time==0){
            time=task[i].second.second;
            idx.push_back(task[i].first);
            count++;
        }
        else{
            if(task[i].second.first>=time){
                time=task[i].second.second;
                idx.push_back(task[i].first);
                count++;
            }
        }
    }
    cout<<"Total no. of processes run = "<<count<<endl;
    cout<<"Processes that ran was/were ";
    for(int i=0;i<count;i++){
        cout<<"p"<<idx[i]<<"  ";
    }
    cout<<endl;

    return 0;
}