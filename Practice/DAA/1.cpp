#include <bits/stdc++.h>
using namespace std;

int ifibo(int n){
    int a=0,b=1,c;

    if(n==0) return a;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
    cout<<"\n";
    return c;
}

int rfibo(int n){
    int c=0;
    c++;
    if(n<0) return 0;
    if (n==1 || n==0) return n;
    return rfibo(n-1)+rfibo(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout << ifibo(n) << "\n";
    cout << rfibo(n-1) << "\n";
}