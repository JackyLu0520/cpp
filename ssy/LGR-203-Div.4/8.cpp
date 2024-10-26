#include<bits/stdc++.h>
using namespace std;
constexpr int N=45;
int n,sum=0,cnt=0;
int p[N];
vector<int>id[N],sc[N],w[N];
int ID;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        for(int j=1;j<=p[i];j++){
            int x;scanf("%d",&x);id[i].push_back(x);
        }
        for(int j=1;j<=p[i];j++){
            int x;scanf("%d",&x);sc[i].push_back(x);
        }
        for(int j=1;j<=p[i];j++){
            int x;scanf("%d",&x);w[i].push_back(x);
        }
    }
    scanf("%d",&ID);
    for(int i=1;i<=n;i++){
        sort(id[i].begin(),id[i].end());
        auto it1=lower_bound(id[i].begin(),id[i].end(),ID);
        if(*it1!=ID) continue;
        int s=sc[i][it1-id[i].begin()];
        sort(sc[i].begin(),sc[i].end());
        auto it2=upper_bound(sc[i].begin(),sc[i].end(),s);
        sum+=w[i][sc[i].end()-it2];cnt++;
    }
    if(sum%cnt==0)  printf("%d",sum/cnt);
    else{
        int a=sum/cnt,b=sum-a*cnt,c=cnt;
        int t=gcd(b,c);b/=t;c/=t;
        printf("%d+%d/%d",a,b,c);
    }
    return 0;
}