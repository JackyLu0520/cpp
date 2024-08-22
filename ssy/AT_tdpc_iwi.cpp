#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;int cnt=0;
    while(s.find("iwii")!=string::npos) s.erase(s.find("iwii"),3),cnt++;
    while(s.find("iiwi")!=string::npos) s.erase(s.find("iiwi")+1,3),cnt++;
    while(s.find("iwi")!=string::npos) s.erase(s.find("iwi"),3),cnt++;
    printf("%d\n",cnt);
    return 0;
}