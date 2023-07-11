#include<fstream>
using namespace std;
int main()
{
	ifstream fin("bike.in"); 
	ofstream fout("bike.out");
	int n;
	fin>>n;
	if(n/3.0+27+23>n/1.2)	fout<<"Walk";
	else if(n/3.0+27+23==n/1.2)	fout<<"All";
	else	fout<<"Bike";
	fin.close();
	fout.close();
	return 0;
}
