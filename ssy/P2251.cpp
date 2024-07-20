#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,a[N];
deque<int> qmin;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(!qmin.empty()&&a[qmin.back()]>=a[i])   qmin.pop_back();
        qmin.push_back(i);
        while(!qmin.empty()&&qmin.front()<=i-k)  qmin.pop_front();
        if(i>=k)    printf("%d\n",a[qmin.front()]);
    }
    return 0;
}