#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll phi[N],prime[N],tot=0;
bool notprime[N];
ll n,ans=0;
int main(){
	scanf("%lld",&n);
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!notprime[i]){
			phi[i]=i-1;
			prime[++tot]=i;		
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			notprime[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
                break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
	for(int i=1;i<=n;i++)
		ans+=phi[i]*(n/i)*(n/i);
	printf("%lld",ans);
	return 0;
}