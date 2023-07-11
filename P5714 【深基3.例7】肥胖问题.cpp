#include<iostream>
using namespace std;
int main(){
	double m,h,bmi;
	cin>>m>>h;
	bmi=m/(h*h);
	if(bmi<18.5)
		cout<<"Underweight";
	else if(bmi>24)
		cout<<bmi<<endl<<"Overweight";
	else
		cout<<"Normal";
	return 0;
}
