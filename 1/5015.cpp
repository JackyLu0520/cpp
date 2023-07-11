#include<iostream>
#include<string>
using namespace std;
int main()
{
	string title;
	getline(cin,title);
	int size_t,i;
	size_t=title.size();
	for(i=0;i<title.size();i++)
		if(title[i]==' ')
			size_t--;
	cout<<size_t;
	return 0;
}
