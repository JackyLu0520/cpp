#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,c[N];
int main(){
    scanf("%d",&n);n++;
    if(n==2){printf("1\n1");return 0;}
    if(n==3){printf("1\n1 1");return 0;}
    fill(c+1,c+n+1,1);
    c[1]=2;
    for(int i=2;i<=n;i++)
        if(c[i]==1)
            for(int j=i+i;j<=n;j+=i)
                c[j]=2;
    printf("2\n");
    for(int i=2;i<=n;i++)
        printf("%d ",c[i]);
    return 0;
}