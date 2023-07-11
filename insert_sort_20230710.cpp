#include<iostream>
using namespace std;
const int MAXN=10000;
int n,a[MAXN+10];
void insert_sort(){
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=0&&a[j]>a[j+1];j--)
            swap(a[j],a[j+1]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    insert_sort();
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}