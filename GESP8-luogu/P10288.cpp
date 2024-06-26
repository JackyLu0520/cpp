#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        map<int,vector<int>>m;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int t;
            scanf("%d",&t);
            m[t].push_back(i);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            vector<int>::iterator lit=lower_bound(m[x].begin(),m[x].end(),l);
            vector<int>::iterator rit=upper_bound(m[x].begin(),m[x].end(),r);
            printf("%d\n",rit-lit);
        }
    }
    return 0;
}