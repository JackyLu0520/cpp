#include<bits/stdc++.h>
using namespace std;
const int N=10,A=10;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    int n=rand()%N+1;
    int m=rand()%n;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++)
        printf("%d ",rand()%A+1);
    return 0;
}