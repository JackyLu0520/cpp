#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,x[N];
vector<int>a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        for(int j=1;j<=x[i];j++){
            int t;
            scanf("%d",&t);
            a[i].push_back(t);
        }
    }
    for(int i=1;i<=n;i++){
        bool b[N]={0};
        for(int j:a[i])
            for(int k:a[j])
                b[k]=1;
        for(int j=1;j<=n;j++)
            if(b[j])
                x[i]++;
        if(b[i])    x[i]--;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);
    return 0;
}