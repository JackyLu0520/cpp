#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,h[N],p[2][N];
stack<int>s1,s2;
int main(){
    freopen("bio.in","r",stdin);
    freopen("bio.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
        while(!s1.empty()&&h[s1.top()]<=h[i]) s1.pop();
        p[0][i]=s1.empty()?0:s1.top();
        s1.push(i);
    }
    for(int i=n;i>=1;i--){
        while(!s2.empty()&&h[s2.top()]<=h[i]) s2.pop();
        p[1][i]=s2.empty()?n+1:s2.top();
        s2.push(i);
    }
    while(m--){
        char op[5];scanf("%s",op);
        if(op[0]=='U'){
            int id,h1;scanf("%d%d",&id,&h1);
            h[id]=h1;
            for(int i=1;i<=n;i++){
                if(i<id&&p[1][i]>id&&h[i]<h1)
                    p[1][i]=id;
                if(i>id&&p[0][i]<id&&h[i]<h1)
                    p[0][i]=id;
            }
            p[0][id]=0;
            for(int i=id-1;i>=1;i--)
                if(h[id]<h[i]){
                    p[0][id]=i;break;
                }
            p[1][id]=n+1;
            for(int i=id+1;i<=n;i++)
                if(h[id]<h[i]){
                    p[1][id]=i;break;
                }
        }else if(op[0]=='L'||op[0]=='R'){
            int dir=(op[0]=='R'),pos;
            scanf("%d",&pos);
            while(p[dir][pos]!=0&&p[dir][pos]!=n+1)
                pos=p[dir][pos],dir=!dir;
            printf("%d\n",pos);
        }
        /*for(int i=1;i<=n;i++)
            printf("%5d",h[i]);
        printf("\n");
        for(int i=1;i<=n;i++)
            printf("%5d",p[0][i]);
        printf("\n");
        for(int i=1;i<=n;i++)
            printf("%5d",p[1][i]);
        printf("\n");*/
    }
    return 0;
}