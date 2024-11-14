#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e3+10,MOD=998244353;
int n,m,c,f;
int red[N][M],ced[N][M];
int sc[N][M],sf[N][M];
char s[N][M];
int ansc,ansf;
int main(){
    int _;
    scanf("%d%*d",&_);
    while(_--){
        scanf("%d%d%d%d",&n,&m,&c,&f);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            s[i][m+1]='1';
        for(int j=1;j<=m;j++)
            s[n+1][j]='1';
        for(int i=1;i<=n;i++)
            for(int j=m+1;j>=1;j--){
                if(s[i][j]=='1')    red[i][j]=j-1;
                else                red[i][j]=red[i][j+1];
            }
        for(int j=1;j<=m;j++)
            for(int i=n+1;i>=1;i--){
                if(s[i][j]=='1')    ced[i][j]=i-1;
                else                ced[i][j]=ced[i+1][j];
            }
        //debug
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%d ",red[i][j]);
            printf("\n");
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%d ",ced[i][j]);
            printf("\n");
        }*/
        //
        //C
        ansc=0;
        memset(sc[0],0,sizeof(sc[0]));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sc[i][j]=(sc[i-1][j]+red[i][j]-j)%MOD;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(ced[i][j]>i)
                    ansc=(ansc+1ll*(red[i][j]-j)*(sc[ced[i][j]][j]-sc[i+1][j])%MOD)%MOD;
        //F
        ansf=0;
        memset(sf[0],0,sizeof(sf[0]));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sf[i][j]=(sf[i-1][j]+1ll*(red[i][j]-j)*(ced[i][j]-i)%MOD)%MOD;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(ced[i][j]>i)
                    ansf=(ansf+1ll*(red[i][j]-j)*(sf[ced[i][j]][j]-sf[i+1][j])%MOD)%MOD;
        printf("%d %d\n",c*ansc,f*ansf);
    }
    return 0;
}