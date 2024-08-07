#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int main(){
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        int opt,x;
        scanf("%d%d",&opt,&x);
        switch(opt){
            case 1:a.insert(lower_bound(a.begin(),a.end(),x),x);break;
            case 2:a.erase(lower_bound(a.begin(),a.end(),x));break;
            case 3:printf("%d\n",(lower_bound(a.begin(),a.end(),x)-a.begin()+1));break;
            case 4:printf("%d\n",a[x-1]);break;
            case 5:printf("%d\n",*(lower_bound(a.begin(),a.end(),x)-1));break;
            case 6:printf("%d\n",*upper_bound(a.begin(),a.end(),x));break;
            default:break;
        }
        /*printf("\na:");
        for(auto i:a)   printf("%d ",i);
        printf("\n");*/
    }
    return 0;
}