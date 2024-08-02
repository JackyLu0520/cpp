#include<bits/stdc++.h>
using namespace std;
const int N=10,X=1e7;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    int t=rand()%N+1;
    printf("%d\n",t);
    vector<int>a;
    while(t--){
        int op=rand()%6+1;
        int x,p;
        switch(op){
            case 1:x=rand()%(2*X)-X;a.push_back(x);sort(a.begin(),a.end());break;
            case 2:p=rand()%(a.size());x=a[p];a.erase(a.begin()+p);break;
            case 3:x=rand()%(a[a.size()-1]-a[0])+a[0];break;
            case 4:x=rand()%(a.size())+1;break;
            case 5:x=rand()%(a[a.size()-1]-a[0])+a[0];break;
            case 6:x=rand()%(a[a.size()-1]-a[0])+a[0];break;
        }
        printf("%d %d\n",op,x);
    }
    return 0;
}