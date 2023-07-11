#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e5;
struct E{int v,w;E(){}E(int V,int W){v=V,w=W;}};
vector<E> adj[MAXN+10];
int n,a[MAXN+10];
void dfs(int u,int pre){
    for(auto e:adj[u])
        if(e.v!=pre){
            a[e.v]=a[u]^e.w;
            dfs(e.v,u);
        }
}
//Trie
struct node{struct node* next[2];};
struct node* root;
void insert(int n){
    struct node* p=root;
    for(int i=1;i<=(1<<30);i<<=1){
        bool c=n&i;
        if(p->next[c]==NULL)
            p->next[c]=new node;
        p=p->next[c];
    }
}
int find(int n){
    struct node* p=root;
    int ans=0;
    for(int i=1;i<=(1<<30);i<<=1){
        bool c=n&i;
        if(p->next[!c]!=NULL){
            ans+=i;
            p=p->next[!c];
        }else
            p=p->next[c];
    }
    return ans;
}
//
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(E(v,w));
        adj[v].push_back(E(u,w));
    }
    dfs(1,0);
    root=new node;
    for(int i=1;i<n;i++)
        insert(a[i]);
    int ans=0;
    for(int i=1;i<n;i++)
        ans=max(ans,find(a[i]));
    printf("%d",ans);
    return 0;
}