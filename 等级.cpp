#include<iostream>
using namespace std;
int main()
{
	float n;
	char score;
	cin>>n;
	switch(int(n/10))
	{
		case 10:
		case 9:   score='A';break;
		case 8:
		case 7:   score='B';break;
		case 6:   score='C';break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:	
		case 0:   score='D';break;
		default:   score=' ';break;		 
	} 
	cout<<score;
	return 0;    
}
