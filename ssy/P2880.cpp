#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,L=17;
int n,q;
int h[N];
int Max[N][L],Min[N][L],lg[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        Max[i][0]=Min[i][0]=h[i];
    }
    for(int j=1;j<L;j++)
        for(int i=1;i+(1<<(j-1))<=n;i++)
        {
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
            Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
        }
    for(int i=2;i<=n;i++)
        lg[i]=lg[i>>1]+1;
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<L;j++){
            printf("%d ",Max[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<L;j++){
            printf("%d ",Min[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        printf("%d ",lg[i]);*/
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int t=lg[b-a+1];
        int Mx=max(Max[a][t],Max[b-(1<<t)+1][t]);
        int Mn=min(Min[a][t],Min[b-(1<<t)+1][t]);
        printf("%d\n",Mx-Mn);
    }
    return 0;
}