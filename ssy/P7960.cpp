#include<bits/stdc++.h>
using namespace std;
const int X=1e7;
int nxt[X+10],pre[X+10];
bool b[X+10];
inline int p(int x){
    while(x){
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
int main(){
    for(int i=1;i<=X;i++)
        nxt[i]=i+1,pre[i]=i-1;
    for(int i=1;i<=X;i++)
        if(p(i)){
            for(int j=i;j<=X;j+=i)
                if(!b[j]){
                    pre[nxt[j]]=pre[j];
                    nxt[pre[j]]=nxt[j];
                    b[j]=1;
                }
        }
    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        printf("%d\n",!b[x]?nxt[x]:-1);
    }
    return 0;
}