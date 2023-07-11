#include<fstream>
using namespace std;
int main()
{
	ifstream fin("train.in"); 
	ofstream fout("train.out");
	int start,end,hh,mm;
	fin>>start>>end;
	hh=end/100-start/100;
	mm=end%100-start%100;
	if(mm<0)
	{
		mm=60-mm;
		hh--;
	}
	if(hh<10)	fout<<"0"<<hh<<":";
	else	fout<<hh<<":";	
	if(mm<10)	fout<<"0"<<mm;
	else	fout<<mm;
	fin.close();
	fout.close();
	return 0;
}
