#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,a[N][N],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+n+1);
        ans=max(ans,a[i][n-1]);
    }
    printf("1\n%d",ans);
    return 0;
}