#include<bits/stdc++.h>
using namespace std;
const int N=100,A=1e9;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
int main(){
    freopen("data.in","w",stdout);
    int n=Rand()%N+1,k=Rand()%N+1,q=Rand()%n+1;
    printf("%d %d %d\n",n,k,q);
    for(int i=1;i<=n;i++)
        printf("%d ",Rand()%A+1);
    printf("\n");
    for(int i=1;i<=n;i++)
        printf("%d\n",Rand()%n+1);
    return 0;
}