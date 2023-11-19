#include <bits/stdc++.h>
using namespace std;

class QuickSort{

    // vector<int> v;
    // int n;

    public:

    // QuickSort(){
    //     int temp;
    //     cout<<"Enter size:";
    //     cin>>temp;
    //     this->n = temp;

    //     for(int i=0;i<n;i++){
    //         int a;
    //         cin>>a;
    //         v.push_back(a);
    //     }
    // }

    int partition(vector<int> &v,int low,int high){
        int pivot = v[high];
        int i = low-1;

        for(int j=low;j<high;j++){
            if(v[j]<pivot){
                i++;
                swap(v[i],v[j]);
            }
        }
        swap(v[i+1],v[high]);
        return i+1;
    }

    void quicksort(vector<int> &v,int low,int high){
        if(low<high){
            int part = partition(v,low,high);
            quicksort(v,low,part-1);
            quicksort(v,part+1,high);
        }
    }

    int partition_r(vector<int> &v,int low,int high){
        int ri = low+rand()%(high-low+1);
        int pivot = v[ri];
        int i = low-1;
        swap(v[high],v[ri]);

        for(int j=low;j<high;j++){
            if(v[j]<=pivot){
                i++;
                swap(v[i],v[j]);
            }
        }
        swap(v[i+1],v[high]);
        return i+1;
    }

    void quicksort_r(vector<int> &v,int low,int high){
        if(low<high){
            int part = partition_r(v,low,high);
            quicksort_r(v,low,part-1);
            quicksort_r(v,part+1,high);
        }
    }
};

int main()
{
    QuickSort q;

    vector<int> v;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    q.quicksort_r(v, 0, n - 1);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}