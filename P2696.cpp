#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,k,num,n,m=2,ns;
	cin>>n;
	ns=n;
	bool a[100001];
	while(1){
		memset(a,0,sizeof(a));
		for(i=0,k=0,num=0;num!=n;){
			i++;
			if(i>n)		i=1;
			if(!a[i])	k++;
			if(k==m){
				a[i]=1;
				num++;
				k=0;
			}
		}
		if(i==n)	break;
		n=i;
	}
	cout<<ns+n<<endl;
	return 0;
}
