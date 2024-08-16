#include<bits/stdc++.h>
using namespace std;
string s,m="friend";int pre=-20,ans=0;
int main(){
    cin>>s;
    for(int i=0;i<s.size()-5;i++){
        bool f=1;
        for(int j=0;j<6;j++)
            if(s[i+j]!=m[j])
                f=0;
        if(f){
            if(i-pre>8){
                pre=i;ans++;
            }else{
                pre=-20;
            }
        }
    }
    printf("%d",ans);
    return 0;
}