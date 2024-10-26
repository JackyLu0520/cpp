#include<bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    node *s[70];
    node(){
        cnt=0;
        for(int i=0;i<70;i++)
            s[i]=nullptr;
    }
};
node *root;
int num(char c){
    if(c>='0'&&c<='9')  return c-'0';
    else if(c>='A'&&c<='Z') return c-'A'+10;
    return c-'a'+10+26;
}
void insert(string s){
    node *p=root;
    for(int i=0;i<s.size();i++){
        int c=num(s[i]);
        if(p->s[c]==nullptr)
            p->s[c]=new node;
        p=p->s[c];
        p->cnt++;
    }
}
int query(string s){
    node *p=root;
    for(int i=0;i<s.size();i++){
        int c=num(s[i]);
        if(p->s[c]==nullptr)
            return 0;
        p=p->s[c];
    }
    return p->cnt;
}
int main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        root=new node;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        for(int i=1;i<=q;i++){
            string s;
            cin>>s;
            cout<<query(s)<<endl;
        }
    }
    return 0;
}