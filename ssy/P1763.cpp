#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b){
    return a/gcd(a,b)*b;
}
struct frac{
    long long a,b;//a/b;
    frac(){}
    frac(long long _a,long long _b){a=_a,b=_b;}
    void simp(){
        long long t=gcd(abs(a),abs(b));
        a/=t;b/=t;
        if(b<0) a=-a,b=-b;
    }
};
frac operator+(const frac& x,const frac& y){
    frac ans;
    ans.b=lcm(x.b,y.b);
    ans.a=x.a*ans.b/x.b+y.a*ans.b/y.b;
    ans.simp();
    return ans;
}
frac operator-(const frac& x){
    frac ans(-x.a,x.b);
    ans.simp();
    return ans;
}
frac operator-(const frac& x,const frac& y){
    return x+(-y);
}
frac n;
void dfs(int depth,int maxdepth,frac now){
    if(depth>maxdepth)  return;
    if(now.a==1){
        
    }
}
int main(){
    scanf("%d%d",n.a,n.b);

}