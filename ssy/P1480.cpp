#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long a[N]={0},n=0,b;
char c;
bool f1=0,f2=0;
int main(){
    while((c=getchar())!='\n')  a[++n]=c-'0';
    scanf("%lld",&b);
    for(int i=1;i<=n+10;i++)    printf("%lld",a[i]);
    printf("\n");
    for(int i=1;i<=n;i++){
        if(a[i]/b!=0||f2){printf("%lld",a[i]/b);f1=1;f2=1;}
        a[i+1]+=(a[i]%b)*10;
    }
    if(!f1)  printf("0");
    return 0;
}