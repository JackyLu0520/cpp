#include<bits/stdc++.h>
using namespace std;
void search(int l,int r,int k){
	while(l<=r){
		int mid=(l+r)/2;
		cout<<mid<<endl;
		if(k==mid){cout<<"ÕÒµ½ÁË£¡";break;}
		else if(k<mid)	r=mid-1;
		else if(k>mid)	l=mid+1;
	}
}
int main(){
	int k;
	cin>>k;
	search(1,100,k);
	return 0;
} 
