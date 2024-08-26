#include<bits/stdc++.h>
using namespace std;
char c;
bool cp=0,spj=0;
int main(){
    cout<<"Compile?(y/n)";
    cin>>c;
    cp=(c=='y');
    cout<<"Special Judge?(y/n)";
    cin>>c;
    spj=(c=='y');
    if(cp){
        cout<<"gen.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o gen.exe gen.cpp");
        cout<<"bf.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o bf.exe bf.cpp");
        cout<<"sol.cpp"<<endl;
        system("g++ -O2 -std=c++14 -static -o sol.exe sol.cpp");
        if(spj){
            cout<<"spj.cpp"<<endl;
            system("g++ -O2 -std=c++14 -static -o spj.exe spj.cpp");
        }
    }
    for(int i=1;;i++){
        cout<<"#"<<i<<endl;
        system("gen.exe");
        system("bf.exe");
        system("sol.exe");
        if(!spj){
            if(system("fc.exe bf.out sol.out")){
                cout<<"Continue?(y/n)";
                cin>>c;
                if(c=='n') break;
            }
        }else{
            system("spj.exe");
            ifstream fin("res.out");
            string s;getline(fin,s);
            cout<<s<<endl;
            if(s[0]!='A'){
                cout<<"Continue?(y/n)";
                cin>>c;
                if(c=='n') break;
            }
        }
    }
    return 0;
}