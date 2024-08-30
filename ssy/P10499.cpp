#include<bits/stdc++.h>
using namespace std;
const int N=35;
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        int n;scanf("%d",&n);
        bitset<N>a[N];
        for(int i=1;i<=n;i++){
            int t;scanf("%d",&t);
            a[i][n+1]=(t==1);
        }
        for(int i=1;i<=n;i++){
            int t;scanf("%d",&t);
            a[i][n+1]=a[i][n+1]^(t==1);
        }
        while(1){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==0&&y==0)  break;
            a[y][x]=1;
        }
        for(int i=1;i<=n;i++)
            a[i][i]=1;
        int r=1,c=1;
        for(;r<=n&&c<=n;c++){
            int t=r;
            for(;t<=n&&!a[t][c];t++);
            if(t>n) continue;
            swap(a[r],a[t]);
            for(int i=1;i<=n;i++)
                if(r!=i&&a[i][c])
                    a[i]^=a[r];
            r++;
        }
        if(r<n+1){
            bool f1=0;
            for(int i=r;i<=n;i++){
                bool f2=1;
                for(int j=1;j<=n;j++)
                    if(a[i][j]){
                        f2=0;break;
                    }
                if(f2&&a[i][n+1]){
                    f1=1;break;
                }
            }
            if(f1)  printf("Oh,it's impossible~!!\n");
            else    printf("%d\n",(1<<(n-r+1)));
        }else   printf("1\n");
    }
    return 0;
}