#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int>A,B;
int ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;scanf("%d",&a);
        A.push(a);
    }
    for(int i=1;i<=n;i++){
        int b;scanf("%d",&b);
        B.push(b);
    }
    while(!A.empty()){
        if(A.top()>B.top()){
            A.push(A.top()/2);
            A.pop();
        }else if(A.top()<B.top()){
            if(B.top()&1)   {printf("-1\n");return 0;}
            B.push(B.top()/2);
            B.pop();
        }else{
            A.pop();B.pop();
            continue;
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}