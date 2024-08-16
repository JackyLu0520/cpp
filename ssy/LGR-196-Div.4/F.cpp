#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e3+10;
int n,m;
vector<int> a[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int c;scanf("%d",&c);
        a[c].push_back(i);
    }
    for(int i=0;i<n/m;i++)
        for(int j=1;j<=m;j++)
            printf("%d\n",a[j][i]);
    return 0;
}