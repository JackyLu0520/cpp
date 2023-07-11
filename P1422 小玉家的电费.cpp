#include<iostream>
using namespace std;
int main(){
	int n;
	float a;
	cin>>n;
	if(n<=150)	a=0.4463*n;
	if(n>150&&n<=400)	a=0.4463*150+0.4663*(n-150);
	if(n>400)	a=0.4463*150+0.4663*(400-150)+0.5663*(n-400);
	cout<<int(a*10+0.5)/10.0;
	return 0;
}
