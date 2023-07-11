#include<iostream>
#include<cstring>
using namespace std;
int n,q,trie[3000010][63],cnt[3000010],triep;
char s[3000010];
void clear(){
    triep=0;
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
}
int num(char c){
    if(c>='0'&&c<='9')  return c-'0';
    if(c>='A'&&c<='Z')  return c-'A'+10;
    return  c-'a'+36;
}
void insert(char s[]){
    int p=0,l=strlen(s);
    for(int i=0;i<l;i++){
        int c=num(s[i]);
        if(!trie[p][c])
            trie[p][c]=++triep;
        p=trie[p][c];
        cnt[p]++;
    }
}
int find(char s[]){
    int p=0,l=strlen(s);
    for(int i=0;i<l;i++){
        int c=num(s[i]);
        if(!trie[p][c]) return 0;
        p=trie[p][c];
    }
    return cnt[p];
}
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        clear();
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
