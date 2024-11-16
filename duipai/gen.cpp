#include<bits/stdc++.h>
using namespace std;
const int N=20,A=20;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
inline int randint(int l,int r){
    return Rand()%(r-l+1)+l;
}
int main(){
    freopen("data.in","w",stdout);
    int n=randint(1,N);
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
        printf("%d ",randint(1,A));
    printf("\n");
    int q=randint(1,N);
    printf("%d\n",q);
    for(int i=1;i<=q;i++)
        printf("%d %d\n",randint(1,n),randint(1,A));
    return 0;
}