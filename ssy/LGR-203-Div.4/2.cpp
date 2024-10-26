#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    if(a-b>=0)   printf("%d ",a-b);
    if(a+b<=n&&b!=0)  printf("%d ",a+b);
    if(a-b<0&&a+b>n)   printf("No solution");
    return 0;
}