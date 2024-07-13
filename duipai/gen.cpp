#include<bits/stdc++.h>
using namespace std;
const int N=10,C=10,Q=10;
int n,q;
int c[N+10];
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    n=rand()%N+1;q=rand()%Q+1;
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++)   printf("%d ",rand()%C+1);
    printf("\n");
    while(q--){
        int op=rand()%2+1;
        if(op==1){
            int r=rand()%n+1,l=rand()%(r-1)+1;
            printf("%d %d %d %d\n",op,l,r,rand()%C+1);
        }else{
            printf("%d %d\n",op,rand()%(n-1)+1);
        }
    }
    return 0;
}