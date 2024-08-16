#include<bits/stdc++.h>
using namespace std;
int w1,c1,t1,w2,t2,c2;
int main(){
    scanf("%d%d%d%d%d%d",&w1,&c1,&t1,&w2,&c2,&t2);
    if(w1>w2)   printf("A");
    else if(w1<w2)  printf("B");
    else if(c1>c2)  printf("A");
    else if(c1<c2)  printf("B");
    else if(t1<t2)  printf("A");
    else            printf("B");
    return 0;
}