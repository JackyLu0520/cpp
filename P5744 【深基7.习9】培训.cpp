#include<bits/stdc++.h>
using namespace std;
struct stu{
	string name;
	int age;
	int score;
}students[1000000];
int n;
int main(){
	int i;
	scanf("%d",&n);
	//cin>>n;
	for(i=0;i<n;i++)
		cin>>students[i].name
		>>students[i].age>>
		students[i].score;
	for(i=0;i<n;i++)
		cout<<students[i].name<<' '<<
		students[i].age+1<<' '<<
		(students[i].score*1.2>600?600:students[i].score*1.2)<<endl;
	return 0;
} 
