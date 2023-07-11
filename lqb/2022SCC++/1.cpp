#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n%10<3)  cout<<n/10;
    else        cout<<ceil(n/10.0);
    return 0;
}
