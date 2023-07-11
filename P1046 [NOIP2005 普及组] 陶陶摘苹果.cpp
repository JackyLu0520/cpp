#include<iostream>
using namespace std;
int main(){
	int a[11],h,s=0,i;
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]
		>>a[6]>>a[7]>>a[8]>>a[9]>>a[10]>>h;
	h+=30;
	for(i=1;i<=10;i++)
		if(h>=a[i])
			s++;
	cout<<s;
	return 0;
}
