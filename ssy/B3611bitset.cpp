#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
bitset<N> a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int t;scanf("%d",&t);
            a[i].set(j,t);
        }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
            if(a[i][j])
                a[i]|=a[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            putchar(a[i][j]+'0'),putchar(' ');
        putchar('\n');
    }
    return 0;
}