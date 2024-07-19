#include<bits/stdc++.h>
using namespace std;
int x,y,z,w;
int main(){
    scanf("%d%d%d%d",&x,&y,&z,&w);
    if(z!=0&&w!=0&&x/z==y/w&&x%z==0&&y%w==0)    printf("%d",x/z);
    else if((x==0&&z==0)&&w!=0&&y%w==0)    printf("%d",y/w);
    else if(z!=0&&(y==0&&w==0)&&x%z==0)    printf("%d",x/z);
    else                            printf("-1");
    return 0;
}