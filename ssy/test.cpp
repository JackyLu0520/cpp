#include<bits/stdc++.h>
using namespace std;
mt19937 Rand(time(0));
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--)  printf("%d %d\n",Rand()%n+1,Rand()%n+1);
    return 0;
}