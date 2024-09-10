#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
void print(__int128 x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<10)
	{
		putchar(x+48);
		return;
	}
	print(x/10);
	putchar(x%10+48);
}
__int128 sum=0,sqsum=0,ans;
__int128 max(__int128 a,__int128 b){
    return a>b?a:b;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        sum+=a[i];sqsum+=1ll*a[i]*a[i];
    }
    for(int i=n;i>=1;i--){
        sum+=b[i]-a[i];sqsum+=1ll*b[i]*b[i]-1ll*a[i]*a[i];
        ans=max(ans,n*sqsum-sum*sum);
    }
    print(ans);
    return 0;
}