#include<bits/stdc++.h>
using namespace std;
int f,n,cnt=0;
int main(){
	int i,j;
	cin>>f>>n;
	for(i=1;i<=f;i++)
		for(j=1;j<=n;j++){
			int num=i*100+j,m=0,t;
			t=num;
			while(t){
				m=m*10;
				if(t%10==0||t%10==1||t%10==8)
					m+=t%10;
				else if(t%10==6)
					m+=9;
				else if(t%10==9)
					m+=6;
				t/=10;
			}
			if(m==num)
				cnt++;
		}
	cout<<cnt;
	return 0;
}
