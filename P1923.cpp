#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e6+10;
int n,k,a[MAXN];
void qsort(int l,int r){
    if(l>r) return;
    int i=l,j=r,p=a[(l+r)/2];
    while(i<=j){
        while(a[i]<p)i++;
        while(a[j]>p)j--;
        if(i<=j){swap(a[i],a[j]);i++;j--;}
    }
    if(k+1<=j)qsort(l,j);
    else if(k+1>=i)qsort(i,r);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(1,n);
    printf("%d",a[k+1]);
    return 0;
}