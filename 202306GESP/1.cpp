#include<bits/stdc++.h>
using namespace std;
int getsum(long long n){
    int sum=0,num=n;
    while(num){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int convert(int n){
    if(n>9)   return convert(getsum(n));
    return n;
}
bool check(long long n){
    long long num=n,res=0;
    bool isodd=1;
    while(num){
        res=res*10+(isodd?convert(num%10*7):num%10);
        num/=10;
        isodd=!isodd;
    }
    if(getsum(res)%8==0)    return 1;
    return 0;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        long long num;
        cin>>num;
        cout<<(check(num)?'T':'F')<<endl;
    }
    return 0;
}
