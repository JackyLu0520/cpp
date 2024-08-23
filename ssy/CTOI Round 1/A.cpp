#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int j=1;bool f=0;
        while(j<=n){
            while(a[j]%i!=0&&j<=n)  j++;
            if(j>n) break;
            if(a[j]==i){j++;continue;}
            int t=a[j];
            while(a[j]%i==0&&j<=n)  t=gcd(t,a[j]),j++;
            if(t==i){f=1;break;}
            if(j>n) break;
        }
        if(f)   printf("%d ",n);
        else    printf("%d ",n-1);
    }
    return 0;
}