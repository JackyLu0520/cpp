//unfinished
#include<bits/stdc++.h>
using namespace std;
int a[110]={0},b[110]={0};
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int acur=0,bcur=100,x,y,Max=0,acnt,bcnt;
		cin>>x>>y;
		a[x]++;
		b[y]++;
		while(a[acur]==0)	acur++;
		while(b[bcur]==0)	bcur--;
		acnt=a[acur];
		bcnt=b[bcur];
		Max=acur+bcur;
		while(1){
			if(acnt==bcnt){
				acur++;
				bcur--;
				while(a[acur]==0)	acur++;
				while(b[bcur]==0)	bcur--;
				acnt=a[acur];
				bcnt=b[bcur];
			}else if(acnt>bcnt){
				acnt-=bcnt;
				bcur--;
				while(b[bcur]==0)	bcur--;
				bcnt=b[bcur];
			}else{
				bcnt-=acnt;
				acur++;
				while(a[acur]==0)	acur++;
				acnt=a[acur];
			}
			if(acur<=100&&bcur>=1)
				Max=max(Max,acur+bcur);
			else
				break;
		}
		cout<<Max<<endl;
	}
	return 0;
}