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
        system("g++ -O2 -std=c++14 -o gen gen.cpp");
        cout<<"bf.cpp"<<endl;
        system("g++ -O2 -std=c++14 -o bf bf.cpp");
        cout<<"sol.cpp"<<endl;
        system("g++ -O2 -std=c++14 -o sol sol.cpp");
        if(spj){
            cout<<"spj.cpp"<<endl;
            system("g++ -O2 -std=c++14 -o spj spj.cpp");
        }
    }
    for(int i=1;;i++){
        cout<<"#"<<i<<endl;
        system("./gen > data.in");
        system("./bf < data.in > bf.out");
        system("./sol < data.in >sol.out");
        if(!spj){
            if(system("diff bf.out sol.out")){
                cout<<"Continue?(y/n)";
                cin>>c;
                if(c=='n') break;
            }
        }else{
            system("./spj > res.out");
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