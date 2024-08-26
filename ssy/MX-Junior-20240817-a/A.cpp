#include<bits/stdc++.h>
using namespace std;
int fa[30],cnt;
void init(){cnt=26;for(int i=1;i<=26;i++)fa[i]=i;}
int query(int x){return x==fa[x]?x:fa[x]=query(fa[x]);}
void merge(int x,int y){int xx=query(x),yy=query(y);if(xx!=yy){cnt--;fa[xx]=yy;}}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        char s[200010];
        int pre[30]={0},nxt[30]={0};
        deque<char>a,b;
        for(char i='z';i>='a';i--)
            a.push_back(i);
        scanf("%s",s);
        init();
        for(int i=0;i<strlen(s);i++){
            if(nxt[s[i]-'a'+1]){s[i]=char(nxt[s[i]-'a'+1]+'a'-1);continue;}
            while(a.back()==s[i]||
                pre[a.back()-'a'+1]||
                (query(a.back()-'a'+1)==query(s[i]-'a'+1)&&
                !(cnt==1&&pre[a.back()-'a'+1]==0))
                ){b.push_back(a.back());a.pop_back();}
            nxt[s[i]-'a'+1]=a.back()-'a'+1;
            pre[a.back()-'a'+1]=s[i]-'a'+1;
            merge(a.back()-'a'+1,s[i]-'a'+1);
            s[i]=a.back();a.pop_back();
            while(!b.empty()){a.push_back(b.back());b.pop_back();}
            /*for(int i=1;i<=26;i++)
                printf("%d ",nxt[i]);
            printf("\n");
            for(int i=1;i<=26;i++)
                printf("%d ",pre[i]);
            printf("\n");
            for(auto it=a.begin();it!=a.end();it++)
                printf("%c ",*it);
            printf("\n");*/
        }
        printf("%s\n",s);
    }
    return 0;
}