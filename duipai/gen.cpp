#include<bits/stdc++.h>
using namespace std;
const int N=15,A=1e9,K=20;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
int main(){
    freopen("data.in","w",stdout);
    int n=Rand()%N+1;
    int m=Rand()%n,k=Rand()%min(n*(n-1)/2,K)+1;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;i++)
        printf("%d ",Rand()%A+1);
    printf("\n");
    vector<int> a;
    for(int i=1;i<=n;i++)
        a.push_back(i);
    for(int i=1;i<=m;i++){
        int x=Rand()%a.size();
        printf("%d ",a[x]);a.erase(a.begin()+x);
        int y=Rand()%a.size();
        printf("%d\n",a[y]);
    }
    vector<pair<int,int>> b;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(Rand()&1)
                b.push_back(make_pair(i,j));
            else
                b.push_back(make_pair(j,i));
    shuffle(b.begin(),b.end(),Rand);
    for(int i=1;i<=k;i++)
        printf("%d %d\n",b[i].first,b[i].second);
    return 0;
}