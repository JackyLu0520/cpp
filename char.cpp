#include<iostream>
using namespace std;
int main()
{
	int i,num,num2;
	char string[2000];
	num=num2=0;
	gets(string);
	for(i=0;string[i]!='\0';i++)
	{
		num++;
		if(string[i]=='.')
		{
			num2++;
		} 
    } 
    puts(string);
    cout<<num<<endl;
    cout<<num2;
    return 0;
}
