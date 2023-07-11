#include<iostream>
using namespace std;
int x, p, m, i, result;
int main(){
	cin >> x >> p >> m;
	result = 1;
	while (p!=1){
		if (p % 2 == 1)
			result = x;
		p /= 2;
		x = result*x*x;
	}
	cout << x%m << endl;
	return 0;
}
