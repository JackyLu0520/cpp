#include<bits/stdc++.h>
using namespace std;
const int RN=2000;
int n;
int cnt[RN]={0},tot=0;
int main(){
    freopen("xyd.in","r",stdin);
    freopen("xyd.out","w",stdout);
    scanf("%d",&n);
    for(int i=RN-1;i>=1;i--){
        while(n>=i*(i+1)/2){
            n-=i*(i+1)/2;cnt[i]++;
        }
        if(!tot&&cnt[i])    tot=i;
    }
    //printf("%d\n",tot);
    for(int i=1;i<=tot;i++){
        printf("XY");
        for(int j=1;j<=cnt[i];j++)
            printf("D");
    }
    return 0;
}