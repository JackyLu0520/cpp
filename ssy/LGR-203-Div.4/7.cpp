#include<bits/stdc++.h>
using namespace std;
int main(){
    int _;string s;
    cin>>_>>s;
    int ans;
    s.push_back('#');
    s.push_back('#');
    //cout<<s<<'\n';
    for(ans=0;;ans++){
        vector<int>pos;
        for(int i=0;i<s.size()-2;i++)
            if(s[i]=='n'&&s[i+1]=='o'&&s[i+2]=='t')
                pos.push_back(i);
        if(pos.empty()) break;
        //for(int i:pos)  cout<<i<<' ';
        //cout<<'\n';
        int cnt=0;
        for(int i:pos){
            s.erase(i-3*cnt,3);
            cnt++;
        }
    }
    s.erase(s.end()-1);
    s.erase(s.end()-1);
    cout<<s<<'\n'<<ans<<'\n';
    return 0;
}