#include<bits/stdc++.h>
using namespace std;
template<class T,int MAXN>
class heap{//top is the biggest
    private:
        T a[MAXN];
        int p=0;
        void siftup(int n){
            while(n>1){
                if(a[n]>a[n/2]){
                    swap(a[n],a[n/2]);
                    n/=2;
                }else
                    break;
            }
        }
        void siftdown(int n){
            int s=n*2;
            while(s<=p){
                if(s<p&&a[s]<a[s+1])    s++;
                if(a[s]>a[n]){
                    swap(a[s],a[n]);
                    n=s;
                    s=n*2;
                }else
                    break;
            }
        }
    public:
        bool empty(){
            return !p;
        }
        void insert(T n){//insert value n
            a[++p]=n;
            siftup(p);
        }
        T top(){//get top
            return a[1];
        }
        void extract(){//remove top
            swap(a[1],a[p--]);
            siftdown(1);
        }
        void remove(int n){//remove a[n]
            if(n>p) return;
            swap(a[n],a[p--]);
            siftup(n);
            siftdown(n);
        }
};
int main(){
    cout<<"MAXN:100"<<endl;
    heap<int,100> h;
    cout<<"Supported commands are:"<<endl;
    cout<<"insert"<<endl;
    cout<<"top"<<endl;
    cout<<"extract"<<endl;
    cout<<"remove"<<endl;
    cout<<"exit"<<endl;
    cout<<endl;
    while(1){
        cout<<">>> ";
        string op;
        cin>>op;
        if(op=="insert"){
            int n;
            cin>>n;
            h.insert(n);
        }else if(op=="top"){
            if(h.empty())   cout<<"The heap is empty."<<endl;
            else    cout<<h.top()<<endl;
        }else if(op=="extract"){
            if(h.empty())   cout<<"The heap is empty."<<endl;
            else    h.extract();
        }else if(op=="remove"){
            int n;
            cin>>n;
            h.remove(n);
        }else if(op=="exit"){
            break;
        }else{
            cout<<"Invalid command."<<endl;
        }
    }
    return 0;
}