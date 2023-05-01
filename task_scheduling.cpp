#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
      return  a.second.second<b.second.second; 
}
int main(){
     
    int n;
    cout<<"Enter no. of tasks :"<<endl;
    cin>>n;
    vector<pair<int,pair<int,int>>>task;
    for(int i=0;i<n;i++){
        int dl,p;
        cout<<"Enter deadline of task"<<i+1<<": ";
        cin>>dl;
        cout<<"Enter Penalty of task"<<i+1<<": ";
        cin>>p;
        pair<int,int>pr=make_pair(dl,p);
        task.push_back({i+1,pr});
    }
    // Finding no/ of processes that can be completed before their deadline 
    int maxDeadl=1;
    for(int i=0;i<n;i++) maxDeadl=max(maxDeadl,task[i].second.first);
    cout<<"Here maximum "<<maxDeadl<<" Processes can run succesfully!"<<endl;
    vector<bool>slot(maxDeadl,0);
    vector<int>idx;
// sorting the tasks according to penalty/profit
    sort(task.begin(),task.end(),compare);

    for(int i=n-1;i>=0;i--){
        int dl=task[i].second.first;
        for(int j=min(dl,maxDeadl)-1;j>=0;j--){
            if(slot[j]==false){
                idx.push_back(i);
                slot[j]=true;
                break;
            }
        }
    }
    int maxp=0;
    cout<<"Tasks that are scheduled in sequence are : ";
   for(int i=0;i<idx.size();i++){
         cout<<"T"<<task[idx[i]].first<<" ";
         maxp+=task[idx[i]].second.second;
   }
   cout<<endl;
   
   cout<<"And max penalty/profit saved/earned is "<<maxp<<endl;
 


    return 0;
}