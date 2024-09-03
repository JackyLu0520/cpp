#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,A=1e6+10;
int n,a[N],cnt[A],ans[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}