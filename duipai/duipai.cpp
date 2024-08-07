#include<bits/stdc++.h>
using namespace std;
char c;
int main(){
    cout<<"Compile?(y/n)";
    cin>>c;
    if(c=='y'){
        cout<<"gen.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o gen.exe gen.cpp");
        cout<<"bf.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o bf.exe bf.cpp");
        cout<<"sol.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o sol.exe sol.cpp");
    }
    for(int i=1;;i++){
        cout<<"#"<<i<<endl;
        system("gen.exe");
        system("bf.exe");
        system("sol.exe");
        if(system("fc bf.out sol.out")){
            cout<<"Continue?(y/n)";
            cin>>c;
            if(c=='n') break;
        }
    }
    return 0;
}