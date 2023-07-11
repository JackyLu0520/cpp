#include<fstream>
using namespace std;
int main()
{
	ifstream fin("average.in"); 
	ofstream fout("average.out");
	int x,y,n1,n2,nan,nv,a;
	fin>>x>>y>>n1>>n2;
	nan=x*n1;
	nv=y*n2;
	a=(nan+nv+0.0)/(n1+n2+0.0)*100+0.5;
	fout<<a/100.00;
	fin.close();
	fout.close();
	return 0;
}
