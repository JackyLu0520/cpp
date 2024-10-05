#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
long long ans=0;
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;scanf("%d",&t);
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    while(!a.empty()){
        if(*(a.end()-1)!=*(a.end()-2)||*(a.end()-1)==0){
            a.pop_back();
            continue;
        }
        while(a.size()>1&&*(a.end()-2)>=*(a.end()-1)){
            if(*(a.end()-1)==0){
                ans+=*(a.end()-2);
                *(a.end()-2)=0;
                a.pop_back();
            }else{
                ans+=*(a.end()-2)-*(a.end()-1)+1;
                *(a.end()-2)=*(a.end()-1)-1;
                a.pop_back();
            }
        }
        a.pop_back();
        /*for(auto it=a.begin();it!=a.end();it++)
            printf("%d ",*it);
        printf("\n");*/
    }
    printf("%lld",ans);
    return 0;
}