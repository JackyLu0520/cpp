#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int L,n,m;
int a[N];
bool check(int x){
    int cnt=0,pre=0;
    for(int i=1;i<=n+1;i++)
        if(a[i]-a[pre]>=x){
            pre=i;
        }else{
            cnt++;
        }
    return cnt<=m;
}
int main(){
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    a[n+1]=L;
    int l=0,r=L;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    printf("%d",l);
    return 0;
}