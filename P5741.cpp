#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct stud
{
	int c,m,e;
	string name;
};
int main()
{
	struct stud studs[1000];
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>studs[i].name>>studs[i].c>>studs[i].m>>studs[i].e;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(abs(studs[i].c-studs[j].c)<=5&&
			abs(studs[i].m-studs[j].m)<=5&&
			abs(studs[i].e-studs[j].e)<=5&&
			abs((studs[i].c+studs[i].m+studs[i].e)-(studs[j].c+studs[j].m+studs[j].e))<=10)
				cout<<studs[i].name<<' '<<studs[j].name<<endl;
	return 0;
}
