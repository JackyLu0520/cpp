#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,A=1e6+10;
int n,a[N],cnt[A],ans[A];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<A;i++)
        if(cnt[i])
            for(int j=i;j<A;j+=i)
                ans[j]+=cnt[i];
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[a[i]]-1);
    return 0;
}