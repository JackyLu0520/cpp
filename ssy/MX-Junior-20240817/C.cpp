#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int N=1e5+10;
int n,k;
int a[N];
double b[N];
bool check(double x){
	int cnt=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		b[i]=a[i]-x;
	}
	double sum;
	for(int i=1;i<=n;){
		if(cnt==k)return true;
		if(!flag)return false;
		sum=0;
		flag=false;
		for(int j=i;j<=n;j++){
			sum+=b[j];
			if(sum>=0){
				cnt++;
				i=j+1;
				flag=true;
				break;
			}
		}
	}
	if(cnt==k)return true;
	return false;
}
/*bool check(double x){
    double sum=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
        b[i]=a[i]-x;
    for(int i=1;i<=n;i++)
        if(sum>=0){
            cnt++;sum=b[i];
        }else{
            sum+=b[i];
        }
    if(sum<0)   return 0;
    return cnt>=k;
}*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double l=0,r=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            r=max(r,1.0*a[i]);
        }
        while(r-l>=eps){
            double mid=(l+r)/2;
            if(check(mid))  l=mid;
            else            r=mid;
        }
        printf("%lf\n",l);
    }
    return 0;
}

