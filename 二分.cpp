#include<iostream>
using namespace std; 
void search(int min,int max,int n){
	int l=min,r=max,mid;
	do{
		mid=(l+r)/2;
		if(mid>n)
			r=mid-1;
		else
			l=mid+1;
		cout<<mid<<endl;
	}while(mid!=n);
	cout<<"¡Ì"; 
}
int main(){
	int n;
	cin>>n;
	cout<<"--------------"<<endl;
	search(1,100,n);
	return 0;
}
