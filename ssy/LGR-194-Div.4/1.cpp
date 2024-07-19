#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d",&a,&b);
    a/=10;b*=10;
    c=10000-a-b;
    printf("%d %d %d",a,b,c);
    return 0;
}