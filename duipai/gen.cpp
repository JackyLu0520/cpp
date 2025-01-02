#include<bits/stdc++.h>
using namespace std;
const int N=20,M=20,A=20;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
inline int randint(int l,int r){
    return Rand()%(r-l+1)+l;
}
int main(){
    printf("1\n");
    int n=randint(1,N),m=randint(1,M);
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++)
        printf("%d ",randint(1,A));
    printf("\n");
    for(int i=1;i<=m;i++){
        int l=randint(0,n-1),r=randint(l,n-1),h=randint(1,A);
        printf("%d %d %d\n",l,r,h);
    }
    return 0;
}