#include<bits/stdc++.h>
using namespace std;
int t,ans;
bitset<100000010>notp;
char s[10];
int m[13]={31,28,31,30,31,30,31,31,30,31,30,31};
void dfs(int step){
    if(step==8){
        int num=0;
        for(int i=7;i>=0;i--)
            num=num*10+s[i]-'0';
        if(num/10000==0)    return;
        if(num%100==0)  return;
        if()
        if(!notp[num]&&!notp[num%10000]&&!notp[num%100])
            ans++;
        return;
    }
    if(s[step]=='-'){
        for(int i=0;i<=9;i++){
            s[step]=char(i+'0');
            dfs(step+1);
        }
        s[step]='-';
    }
    return;
}
int main(){
    scanf("%d",&t);
    for(int i=2;i<=1e8;i++)
        if(!notp[i])
            for(int j=2*i;j<=1e8;j+=i)
                notp.set(j);
    for(int i=1;i<=100;i++)
        if(!notp[i])
            printf("%d ",i);
    printf("\n");
    while(t--){
        scanf("%d",s);
        ans=0;
        dfs(0);
        printf("%d",ans);
    }
    return 0;
}