#include<bits/stdc++.h>
using namespace std;
const int MAXN=150000;
int n;
struct P{long long x,y;P(){}P(long long X,long long Y){x=X;y=Y;}}points[MAXN*2+10];
int a[MAXN+10];
P calc(P p1,P p2,P p3,P p4){
    int a1=p1.y-p2.y,b1=p1.x-p2.x,c1=p2.x*p1.y-p1.x*p2.y;
    int a2=p3.y-p4.y,b2=p3.x-p4.x,c2=p4.x*p3.y-p3.x*p4.y;
    int x=(c1*b2-c1*b1)/(a1*b2-a2*b1),y=(c1*a2-c2*a1)/(b1*a2-b2*a1);
    return P(x,y);
}
/*P midpoint(P p1,P p2){
    return P((p1.x+p2.x)/2,(p1.y+p2.y)/2);
}*/
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        points[i]=P(x,y);
    }
    for(int i=1;i<=n;i++)
        a[i]=i+n;
    do{
        bool f=1;
        P p=calc(points[1],points[a[1]],points[2],points[a[2]]);
        for(int i=2;i<n;i++){
            P p1=calc(points[i],points[a[i]],points[i+1],points[a[i+1]]);
            if(p.x!=p1.x||p.y!=p1.y){
                f=0;
                break;
            }
        }
        if(f){
            printf("%lld%lld",p.x,p.y);
            return 0;
        }
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n%d\n",f);
    }while(next_permutation(a+1,a+n+1));
    printf("NO");
    return 0;
}
/*
input
3
3 5
7 5
6 4
4 6
0 0
10 10

output
5 5
*/