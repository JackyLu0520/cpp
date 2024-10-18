#include<bits/stdc++.h>
using namespace std;
constexpr int N=5010;
bool b[2*N];
int n,p[2*N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=2*n;i++){
        if(b[i])    continue;
        if(p[i]==i){printf("No");return 0;}
        if(p[p[i]]!=i){printf("No");return 0;}
        if(b[p[i]]){printf("No");return 0;}
        b[i]=b[p[i]]=1;
    }
    printf("Yes");
    return 0;
}