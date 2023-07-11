#include<iostream>
using namespace std;
int main(){
	int n,t1,t2;
	cin>>n;
	t1=(n%2==0);
	t2=(n>4&&n<=12);
	cout<<int(t1&&t2)<<' '<<int(t1||t2)<<' '<<int(t1!=t2)<<' '<<int(!t1&&!t2);
	return 0;
}
