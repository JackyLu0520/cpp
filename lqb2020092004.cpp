#include<iostream>
#include<string>
using namespace std;
int main(){
	string words[100000],word,t;
	int s,a;
	cin>>word;
	cin>>t;
	for(int i=0;words[i]=="\n";i++){
		cin>>words[i];
		if(words[i]==word){
			s++;
			if(s==1)
				a=i;
		}
	}
	cout<<s<<' '<<a;
	return 0;
}
