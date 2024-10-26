#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",b==0?1:a/b-a/(b+1));
    }
    return 0;
}