#include<bits/stdc++.h>
using namespace std;
const int N=50;
char s[N+1];
int cnt[10];
long long C[N+1][N+1],ans=0;
int main(){
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        cnt[s[i]-'0']++;
    for(int i=0;i<=strlen(s);i++)
        C[i][0]=C[i][i]=1;
    for(int i=2;i<=strlen(s);i++)
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    for(int i=strlen(s);i>=1;i--){
        for(int j=0;j<s[strlen(s)-i]-'0';j++)
            if(cnt[j]){
                cnt[j]--;
                int l=i-1;long long t=1;
                for(int k=0;k<10;k++){
                    t*=C[l][cnt[k]];l-=cnt[k];
                }
                ans+=t;
                cnt[j]++;
            }
        cnt[s[strlen(s)-i]-'0']--;
    }
    printf("%lld",ans);
    return 0;
}