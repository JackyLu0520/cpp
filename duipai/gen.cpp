#include<bits/stdc++.h>
using namespace std;
const int N=10;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
int main(){
    freopen("data.in","w",stdout);
    int n=Rand()%N+1,k=Rand()%n+1;
    vector<int>a;
    printf("%d %d\n",n,k);
    for(int i=1;i<=k;i++)
        a.push_back(i);
    for(int i=k+1;i<=n;i++)
        a.push_back(Rand()%k+1);
    shuffle(a.begin(),a.end(),Rand);
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}