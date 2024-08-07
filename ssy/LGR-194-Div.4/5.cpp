#include<bits/stdc++.h>
using namespace std;
const int M=1010,N=1010;
int n,m,k,cnt=0;
int a[M][N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++){
        int cnt1=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]==k)
                cnt1++;
        }
        if(cnt1>=(n+1)/2)
            cnt++;
    }
    if(cnt>=(m+1)/2)    printf("YES");
    else                printf("NO");
    return 0;
}