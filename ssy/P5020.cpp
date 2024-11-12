#include<bits/stdc++.h>
using namespace std;
const int N=110,A=25010;
int main(){
    int _;scanf("%d",&_);
    while(_--){
        int n,a[N],b[A]={0},ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            b[a[i]]=2;
        for(int i=1;i<=a[n];i++)
            if(b[i]>0)
                for(int j=1;j<=n;j++)
                    if(i+a[j]<=a[n])
                        b[i+a[j]]=1;
        for(int i=1;i<=a[n];i++)
            ans+=(b[i]==2);
        printf("%d\n",ans);
    }
    return 0;
}