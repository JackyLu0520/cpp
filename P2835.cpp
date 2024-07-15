#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;
int n;
vector<int> adj[MAXN+10];
int main(){
    cin>>n;
    for(int u=1;u<=n;u++){
        int v;
        do{
            cin>>v;
            adj[u].push_back(v);
        }while(v==0);
    }
}