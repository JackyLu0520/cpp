#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a>=0){
        if(b>=0)    cout<<max(a,b);
        else        cout<<(max(a,-b)==a?(-2*b+a):(2*a-b));
    }else{
        if(b>=0)    cout<<(max(-a,b)==b?(-2*a+b):(2*b-a));
        else        cout<<-min(a,b);
    }
    return 0;
}