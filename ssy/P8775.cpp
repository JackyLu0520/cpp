#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,x,y=0,h[N]={0},sum=0;
int main(){
    scanf("%d%d",&n,&x);x<<=1;n--;
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    int l=0,r=0;
    while(r<=n){
        sum-=h[l];
        l++;
        while(r<=n&&sum<x){r++;sum+=h[r];}
        y=max(y,r-l+1);
    }
    printf("%d",y);
    return 0;
}