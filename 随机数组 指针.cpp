#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	int* p;
	srand(time(0));
	for(p=a;p<=a+9;p++)
		*p=rand();
	for(p=a;p<=a+9;p++)
		cout<<*p<<' ';
	return 0;
}
