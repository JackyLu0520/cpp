#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10;
int n=0,m,p;
int a[N];
int c[N];
int lowbit(int x){return x&-x;}
void update()
bool op[M];int x[M];
int main(){
    scanf("%d%d",&m,&p);
    for(int i=1;i<=m;i++){
        char s[3];
        scanf("%s%d",s,&x[i]);
        op[i]=(s[0]=='A');
        n+=op[i];
    }
    int pos=0,pre=0;
    for(int i=1;i<=m;i++)
        if(op[i]){
            ++pos;
            update(pos,(x[i]+pre)%p);
        }else{
            pre=getmax(pos-x[i]+1,pos);
            printf("%d\n",pre);
        }
    return 0;
}