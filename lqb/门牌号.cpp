#include<bits/stdc++.h>
using namespace std;
int main(){
	int F,n,cnt=0,num,t,t1,m=0;
	cin>>F>>n;
	for(int i=1;i<=F;i++)
		for(int j=1;j<=n;j++){
			num=i*100+j;
			t=num;m=0;
			while(num){
				t1=num%10;
				if(t1!=0&&t1!=1&&t1!=8&&t1!=6&&t1!=9)
					break;
				if(t1==6)	t1=9;
				else if(t1==9)	t1=6;
				m=m*10+t1;
				num/=10;
			}
			if(m==t) cnt++;
		}
	cout<<cnt;
	return 0;
}
