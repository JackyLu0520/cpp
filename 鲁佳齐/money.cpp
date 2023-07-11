#include<fstream>
using namespace std;
int main()
{
	ifstream fin("money.in"); 
	ofstream fout("money.out");
	int x,a[12],i,l=0,c;
	for(i=0;i<12;i++)
		fin>>a[i];
	for(i=0;i<12;i++)
	{
		c=(300+l-a[i])/100;
		l=(300+l-a[i])%100;
		if(l+300<a[i+1])
		{
			fout<<-(i+2);
			fin.close();
			fout.close();
			return 0;
		}
	}
	fout<<c+c*0.2;
	fin.close();
	fout.close();
	return 0;
}
