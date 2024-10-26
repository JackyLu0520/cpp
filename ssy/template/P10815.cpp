#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
int read(){
    int sgn=1,n=0;
    char c;
    do{c=getchar();if(c=='-')sgn=-1;}while(!isdigit(c));
    while(isdigit(c)){
        n=(n<<1)+(n<<3)+c-'0';
        c=getchar();
    }
    return sgn*n;
}
void write(int n){
    if(n<0){putchar('-');n=-n;}
    if(n==0)    return;
    write(n/10);
    putchar(n%10+'0');
}
int n,sum=0;
int main(){
    n=read();
    for(int i=1;i<=n;i++)
        sum+=read();
    write(sum);
    return 0;
}