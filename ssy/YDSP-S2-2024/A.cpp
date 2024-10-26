#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
int n,a[N],op[N];
set<int>s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&op[i]);
    op[0]=0;op[n]=1;
    for(int i=1;i<=n;i++)
        if(op[i-1]==0&&op[i]==1)
            s.insert(a[i]);
    printf("%d\n",s.size());
    return 0;
}