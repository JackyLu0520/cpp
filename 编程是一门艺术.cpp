#include<iostream>
#include<string>
using namespace std;
class artist
{
	public:
		void display(string name,int age)
		{
			cout<<"编程是一门艺术\n";
			cout<<"姓名："<<name<<'\n';
			cout<<"年龄："<<age<<'\n';
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
