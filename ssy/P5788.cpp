#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int n,a[N],f[N];
stack<int>s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i])    s.pop();
        if(s.empty())   f[i]=0;
        else    f[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",f[i]);
    return 0;
}