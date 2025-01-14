#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll phi[N],notprime[N],prime[N],tot=0;
ll ans[N];
void prework(){
	phi[1]=1;
	for(ll i=2;i<N;i++){
		if(!notprime[i]){
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(ll j=1;j<=tot&&i*prime[j]<N;j++){
			notprime[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
	for(ll i=1;i<N;i++)
		for(ll j=i;j<N;j+=i)
			ans[j]+=(i*phi[i]+1)/2;
}
int main(){
	prework();
	ll _;
	scanf("%lld",&_);
	while(_--){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",n*ans[n]);
	}
	return 0;
}