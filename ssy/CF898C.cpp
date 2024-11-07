#include<bits/stdc++.h>
using namespace std;
const int N=25;
int trie[10*N*10][10]={0},ed[10*N*10]={0},tot=0;
struct Trie{
    int root,cnt=0;
    Trie(){root=++tot;}
    void insert(string s){
        int p=root;
        for(int i=s.size()-1;i>=0;i--){
            int c=s[i]-'0';
            if(!trie[p][c]){
                trie[p][c]=++tot;
                if(ed[p])   cnt--,ed[p]=0;
            }
            p=trie[p][c];
        }
        bool f=0;
        for(int i=0;i<10;i++)
            if(trie[p][i])
                f=1;
        if(!f&&!ed[p])
            ed[p]=1,cnt++;
    }
    void print(int p,string s){
        if(ed[p]){
            cout<<s<<' ';
            return;
        }
        for(int i=0;i<10;i++)
            if(trie[p][i]){
                print(trie[p][i],(char)(i+'0')+s);
            }
    }
};
map<string,Trie>m;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;int k;
        cin>>s>>k;
        for(int j=1;j<=k;j++){
            string num;
            cin>>num;
            m[s].insert(num);
        }
    }
    cout<<m.size()<<endl;
    for(auto &t:m){
        cout<<t.first<<' '<<t.second.cnt<<' ';
        t.second.print(t.second.root,"");
        cout<<endl;
    }
    return 0;
}