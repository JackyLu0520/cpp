#include<iostream>
#include<iomanip>
using namespace std;
bool ugly_number(int n){
	int m=n;
	while(m%2==0)
		m/=2;
	while(m%3==0)
		m/=3;
	while(m%5==0)
		m/=5;
	return m==1;
}
int main(){
	int i,s=0;
	cout<<"------------------------------------------------"<<endl;
	for(i=1;i<=100;i++)
		if(ugly_number(i)){
			cout<<setw(3)<<i<<'|';
			s++;
			if(s%9==0)
				cout<<endl;
		}
	cout<<s<<"¸ö³óÊý";
	return 0;
}
