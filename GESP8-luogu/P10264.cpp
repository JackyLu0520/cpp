#include<bits/stdc++.h>
using namespace std;
const int N=1.5e4+10,A=15,L=15;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,v[A]={0},nxt[N][L];
        scanf("%d",&n);
        memset(nxt,0x3f,sizeof(nxt));
        for(int i=1;i<=n;i++){
            int tmp;
            scanf("%d",&tmp);
            //printf("%d ",v[tmp]);
            if(!v[tmp])   v[tmp]=i;
            else{nxt[v[tmp]][0]=i;v[tmp]=i;}
        }
        /*
        printf("\n");
        for(int i=1;i<=n;i++){
            for(int j=0;j<L;j++)
                printf("%d ",nxt[i][j]);
            printf("\n");
        }
        printf("\n");
        */
        for(int i=n;i>=1;i--)
            for(int j=1;j<L;j++)
                if(nxt[i][j-1]==0x3f3f3f3f)     nxt[i][j]=0x3f3f3f3f;
                else                            nxt[i][j]=nxt[nxt[i][j-1]+1][j-1];
        /*
        for(int i=1;i<=n;i++){
            for(int j=0;j<L;j++)
                printf("%d ",nxt[i][j]);
            printf("\n");
        }
        */
        int q;
        scanf("%d",&q);
        while(q--){
            int l,r,cnt=0;
            scanf("%d%d",&l,&r);
            for(int i=l;i<=r;i++)
                if(nxt[i][0]>r) cnt++;
                else
                    for(int j=L-1;j>=0;j--)
                        if(nxt[i][j]<=r){
                            i=nxt[i][j];
                            break;
                        }
            printf("%d\n",cnt);
        }
    }
    return 0;
}