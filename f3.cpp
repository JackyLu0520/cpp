#include<fstream>
using namespace std;
int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int t,s;
	while(fin>>t)
		s+=t;
	fout<<s;
	fin.close();
	fin.close();
	return 0;
}

