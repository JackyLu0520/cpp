#include<iostream>
#include<cstring>
using namespace std;
int n,q;
char s[3000010];
struct node{
    int cnt=0;
    struct node* next[63];
};
struct node* root;
int num(char c){
    if(c>='0'&&c<='9')  return c-'0';
    if(c>='A'&&c<='Z')  return c-'A'+10;
    return  c-'a'+36;
}
void insert(char s[]){
    struct node* p=root;
    int l=strlen(s);
    for(int i=0;i<l;i++){
        int c=num(s[i]);
        if(p->next[c]==NULL)
            p->next[c]=new node;
        p=p->next[c];
        p->cnt++;
    }
}
int find(char s[]){
    struct node* p=root;
    int l=strlen(s);
    for(int i=0;i<l;i++){
        int c=num(s[i]);
        if(p->next[c]==NULL) return 0;
        p=p->next[c];
    }
    return p->cnt;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        root=new node;
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}
