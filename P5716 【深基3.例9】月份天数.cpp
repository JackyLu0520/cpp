#include<iostream>
using namespace std;
bool isLeap(int y){
	return y%400==0||y%4==0&&y%100!=0;
}
int main(){
	const int mday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m;
	cin>>y>>m;
	if(m==2)
		cout<<mday[m]+isLeap(y);
	else
		cout<<mday[m];
	return 0;
} 
