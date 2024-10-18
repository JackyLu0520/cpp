#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10;
int n,m;
int val[N];//0:U 1~n:1~n初值 -n~ -1:1~n初值取反 n+1:T -n-1:F
int main(){
    int _;scanf("%*d%d",&_);
    while(_--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            val[i]=i;
        for(int i=1;i<=m;i++){
            char s[5];
            scanf("%s",s);
            switch(s[0]){
                case '+':
                    int x,y;
                    scanf("%d%d",&x,&y);
                    val[x]=val[y];
                    break;
                case '-':
                    int x,y;
                    scanf("%d%d",&x,&y);
                    val[x]=-val[y];
                    break;
                case 'T':
                    int x;
                    scanf("%d",&x);
                    val[x]=n+1;
                    break;
                case 'F':
                    int x;
                    scanf("%d",&x);
                    val[x]=-n-1;
                    break;
                case 'U':
                    int x;
                    scanf("%d",&x);
                    val[x]=0;
                    break;
            }
        }
    }
    
}