#include<iostream>
#include<string>
using namespace std;
class artist
{
	public:
		void display(string name,int age)
		{
			cout<<"�����һ������\n";
			cout<<"������"<<name<<'\n';
			cout<<"���䣺"<<age<<'\n';
			cout<<"--------------------\n"; 
		}
};
int main()
{
	artist stud;
	string name;
	int age;
	cin>>name>>age;
	stud.display(name,age);
	return 0;
}
