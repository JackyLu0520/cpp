#include<bits/stdc++.h>
using namespace std;
int n,q,a[500010],b[500010],l[500010],r[500010];
struct Pair{
    int a,b;
    Pair(){}
    Pair(int A,int B){
        a=A;
        b=B;
    }
};
int main(){
    freopen("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=q;i++)
        cin>>l[i]>>r[i];
    for(int i=1;i<=q;i++){
        stack<Pair> s;
        int cnt=0;
        while(s.size()) s.pop();
        for(int j=l[i];j<=r[i];j++){
            while(s.size()&&(s.top().a==a[j]||s.top().b<=b[j]))
                s.pop();
            s.push(Pair(a[j],b[j]));
            if(s.size()==1) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
