#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000],p=1;
int main(){
    scanf("%d",&n);
    while(n!=1){
        a[p++]=n;
        if(n%2==0) n/=2;
        else    n=n*3+1;
    }
    a[p++]=1;
    for(int i=p-1;i>=1;i--) printf("%d ",a[i]);
    return 0;
}