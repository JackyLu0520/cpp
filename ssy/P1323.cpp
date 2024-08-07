#include<bits/stdc++.h>
using namespace std;
int k,m;
priority_queue<int,vector<int>,greater<int>> q;
string s="";
int main(){
    scanf("%d%d",&k,&m);
    q.push(1);
    for(int i=1;i<=k;i++){
        int t=q.top();q.pop();
        q.push(2*t+1);q.push(4*t+5);
        s+=to_string(t);
    }
    printf("%s\n",s.c_str());
    for(int i=1;i<=m;i++)
        for(int j=0;j<s.size();j++)
            if(s[j]<s[j+1]){
                s.erase(j,1);
                break;
            }
    printf("%s",s.c_str());
    return 0;
}