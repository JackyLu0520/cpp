#include<bits/stdc++.h>
using namespace std;
int n,s,l=1,r=1,maxl=-1,maxr=-1;
int a[1000010];
bool check(int l,int r){
    int sum=0;
    for(int i=l;i<=r;i++){
        sum+=a[i];
        if(sum+s<0) return 0;
    }
    return 1;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(l<=r){
        if(check(l,r)){
            maxl=l;
            maxr=r;
            r++;
        }else{
            l++;
        }
    }
    if(maxl==-1&&maxr==-1)  cout<<-1;
    else                    cout<<maxl<<' '<<maxr;
    return 0;
}
