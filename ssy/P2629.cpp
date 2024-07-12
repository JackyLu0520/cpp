#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,s[N],cnt=0;
deque<int>q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    for(int i=n+1;i<=2*n-1;i++)
        s[i]=s[n]+s[i-n];
    for(int i=1;i<=2*n-1;i++){
        while(!q.empty()&&i-q.front()>n)    q.pop_front();
        while(!q.empty()&&s[q.back()]>=s[i])    q.pop_back();
        q.push_back(i);
        if(i>n-1&&s[i]-s[q.front()]>=0) cnt++;
    }
    printf("%d",cnt);
    return 0;
}