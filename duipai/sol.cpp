#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("data.in","r",stdin);
    freopen("sol.out","w",stdout);
    srand(time(0));
    int a,b;
    cin>>a>>b;
    cout<<((rand()%2)?(a+b):0);
    return 0;
}