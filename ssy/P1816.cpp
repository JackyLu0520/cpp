#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=17;
int n,q;
int h[N];
int Min[N][L],lg[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        Min[i][0]=h[i];
    }
    for(int j=1;j<L;j++)
        for(int i=1;i+(1<<(j-1))<=n;i++)
        {
            Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
        }
    for(int i=2;i<=n;i++)
        lg[i]=lg[i>>1]+1;
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int t=lg[b-a+1];
        int Mn=min(Min[a][t],Min[b-(1<<t)+1][t]);
        printf("%d ",Mn);
    }
    return 0;
}