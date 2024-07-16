#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,X=1e9+10;
int n,c;
int a[N];
bool check(int x){
    int cnt=1,pre=1;
    for(int i=1;i<=n;i++)
        if(a[i]-a[pre]>=x){
            cnt++;pre=i;
        }
    return cnt>=c;
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=X;
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