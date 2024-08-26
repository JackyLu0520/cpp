#include<bits/stdc++.h>
using namespace std;
const int T=5,N=6,A=10;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
int main(){
    freopen("data.in","w",stdout);
    int t=Rand()%T+1;printf("%d\n",t);
    while(t--){
        int n=Rand()%N+1;
        int k=Rand()%n+1;
        printf("%d %d\n",n,k);
        for(int i=1;i<=n;i++)
            printf("%d ",Rand()%A);
        printf("\n");
    }
    return 0;
}