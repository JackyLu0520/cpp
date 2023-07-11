#include<iostream>
using namespace std;
class stud
{
	public:
		int n,s1,s2;
		float s3;
		float s()
		{
			
			return s1+s2;
		}		
}sts[1000];
void e(stud st)
{
	st.s3=st.s1*0.7+st.s2*0.3;
	cout<<((st.s3>=80)&&(st.s()>140)?"Excellent":"Not excellent")<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>sts[i].n>>sts[i].s1>>sts[i].s2;
	for(int i=0;i<n;i++)
		e(sts[i]);
	return 0;
}
