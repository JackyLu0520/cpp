#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN];
void qsort(int l,int r){
    if(l>r) return;
    int i=l,j=r,p=a[(l+r)/2];
    while(i<=j){
        while(a[i]<p)i++;
        while(a[j]>p)j--;
        if(i<=j){swap(a[i],a[j]);i++;j--;}
    }
    qsort(l,j);
    qsort(i,r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(1,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}