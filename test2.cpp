#include<bits/stdc++.h>
using namespace std;
int tgdz[11][13]={0};
int tg1,tg2;
char dz1,dz2;
int main(){
    for(int i=1,j=0,k=0;i<=60;i++,j++,k++){
        if(j>9) j=0;
        if(k>11)    k=0;
        tgdz[j][k]=i;
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%c%d%c",&tg1,&dz1,&tg2,&dz2);
        cout<<tg1<<dz1<<tg2<<dz2;
        int n1=tgdz[tg1][dz1-'A'],n2=tgdz[tg2][dz2-'A'];
        if(n1==0||n2==0)    printf("-1\n");
        else{
            int ans=n1-n2;
            if(ans<0)   ans+=60;
            printf("%d\n",ans);
        }
    }
    return 0;
}

