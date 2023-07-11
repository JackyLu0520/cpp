#include<bits/stdc++.h>
using namespace std;
struct P{int x,y,t;}crimes[100010],cows[100010];
double dis(long long a,long long b){
    return sqrt(a*a+b*b);
}
int main(){
    int g,n,sum=0;
    cin>>g>>n;
    for(int i=1;i<=g;i++)
        cin>>crimes[i].x>>crimes[i].y>>crimes[i].t;
    for(int i=1;i<=n;i++)
        cin>>cows[i].x>>cows[i].y>>cows[i].t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=g;j++)
            if(dis(cows[i].x-crimes[j].x,cows[i].y-crimes[j].y)<=crimes[j].t-cows[i].t){
                sum++;
                //cout<<i<<' '<<j<<endl;
                break;
            }
    cout<<n-sum;
    return 0;
}
