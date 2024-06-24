#include<bits/stdc++.h>
using namespace std;
const int N=210;
const int res[5][5]={
    {0,0,1,1,0},
    {1,0,0,1,0},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {1,1,0,0,0}
};
int n,na,nb,a[N],b[N];
int sa=0,sb=0;
int main(){
    scanf("%d%d%d",&n,&na,&nb);
    for(int i=0;i<na;i++)  scanf("%d",&a[i]);
    for(int i=0;i<nb;i++)  scanf("%d",&b[i]);
    for(int i=0;i<n;i++)    sa+=res[a[i%na]][b[i%nb]],sb+=res[b[i%nb]][a[i%na]];
    printf("%d %d",sa,sb);
    return 0;
}