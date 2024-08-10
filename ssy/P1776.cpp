#include<bits/stdc++.h>
using namespace std;
int n,wmax;
int v[1000010],w[1000010],p=0;
int f[1000010];
int main(){
    scanf("%d%d",&n,&wmax);
    for(int i=1;i<=n;i++){
        int tv,tw,tm,c=1;
        scanf("%d%d%d",&tv,&tw,&tm);
        while(tm>=c){
            v[++p]=tv*c;
            w[p]=tw*c;
            tm-=c;
            c*=2;
        }
        if(tm!=0){
            v[++p]=tv*tm;
            w[p]=tw*tm;
        }
    }
    for(int i=1;i<=p;i++)
        for(int j=wmax;j>=1;j--)
            if(j-w[i]>=0)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
    printf("%d",f[wmax]);
    return 0;
}