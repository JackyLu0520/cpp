#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;
char s1[N],s2[N];
int n1,n2;
int nxt[N],f[N];
int main(){
    scanf("%s%s",s1+1,s2+1);
    n1=strlen(s1+1);n2=strlen(s2+1);
    for(int i=2;i<=n2;i++){
        int j;
        for(j=nxt[i-1];j&&s2[j+1]!=s2[i];j=nxt[j]);
        if(s2[j+1]==s2[i])   nxt[i]=j+1;
        else    nxt[i]=0;
    }
    for(int i=1;i<=n1;i++){
        int j;
        for(j=f[i-1];j&&s2[j+1]!=s1[i];j=nxt[j]);
        if(s2[j+1]==s1[i])   f[i]=j+1;
        else    f[i]=0;
        if(f[i]==n2)
            printf("%d\n",i-n2+1);
    }
    for(int i=1;i<=n2;i++)
        printf("%d ",nxt[i]);
    return 0;
}