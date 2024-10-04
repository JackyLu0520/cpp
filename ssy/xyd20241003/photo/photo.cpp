#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10,K=2e5+10;
int n,k,a[N];
vector<int>stk;
int instk[K],l[K];
int main(){
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        l[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        l[a[i]]--;
        if(instk[a[i]]) continue;
        while(!stk.empty()&&a[i]<stk.back()&&l[stk.back()]){
            instk[stk.back()]--;
            stk.pop_back();
        }
        stk.push_back(a[i]);
        instk[a[i]]++;
    }
    for(int i:stk)
        printf("%d ",i);
    return 0;
}