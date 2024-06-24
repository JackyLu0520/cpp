#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,a[N][N],t[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=(i-1)*n+j;
    while(m--){
        int x,y,r,z;
        scanf("%d%d%d%d",&x,&y,&r,&z);
        for(int i=x-r;i<=x+r;i++)
            for(int j=y-r;j<=y+r;j++)
                t[i][j]=a[i][j];
        if(!z){
            for(int i=x-r;i<=x+r;i++)
                for(int j=y-r;j<=y+r;j++)
                    a[i][j]=t[x+y-j][y-x+i];
        }else{
            for(int i=x-r;i<=x+r;i++)
                for(int j=y-r;j<=y+r;j++)
                    a[i][j]=t[x-y+j][y+x-i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}