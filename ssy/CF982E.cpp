#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,vx,vy;
bool rex,rey;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1;y=0;return a;}
    int d=exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-(a/b)*y;
    return d;
}
pair<int,int> solve(){
    int a,b;
    int d=exgcd(n,m,a,b);
    if((x-y)%d) return pair<int,int>(-1,-1);
    a=a*(x-y)/d;b=b*(x-y)/d;
    a=(a%(m/d)+(m/d))%(m/d);
    b=-(x-y-n*a)/m;
    return pair<int,int>(a,b);
}
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&vx,&vy);
    if(vx==0){
        if(x!=0&&x!=n)
            printf("-1\n");
        else if(vy==-1)
            printf("%d 0\n",x);
        else if(vy==0)
            printf("-1\n");
        else if(vy==1)
            printf("%d %d\n",x,m);
        return 0;
    }else if(vy==0){
        if(y!=0&&y!=m)
            printf("-1\n");
        else if(vx==-1)
            printf("0 %d\n",y);
        else if(vx==1)
            printf("%d %d\n",n,y);
        return 0;
    }
    if(vx==-1)  rex=1,x=n-x;
    if(vy==-1)  rey=1,y=m-y;
    pair<int,int>sol=solve();
    if(sol.first==-1&&sol.second==-1)
        printf("-1\n");
    else{
        int ansx,ansy;
        ansx=(sol.first%2)*n;
        ansy=(sol.second%2)*m;
        if(rex) ansx=n-ansx;
        if(rey) ansy=n-ansy;
        printf("%d %d\n",ansx,ansy);
    }
    return 0;
}