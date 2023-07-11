#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string istr,ostr;
        int next[130]={0},b[130]={0},ans=0;
        cin>>istr>>ostr;
        bool f=0;
        for(int i=0;i<=istr.size();i++)
            if(next[int(istr[i])]==0||next[int(istr[i])]==ostr[i])
                next[int(istr[i])]=ostr[i];
            else
                f=1;
        if(f==1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<130;i++)
            if(next[i]!=0&&next[i]!=i){
                int b1[130]={0},j;
                for(j=i;!b[j]&&j!=next[j];j=next[j])
                    b[j]=1,b1[j]=1,ans++;
                if(b1[j]&&j!=next[j])
                    ans++;
                //cout<<ans<<endl;
            }
        cout<<ans<<endl;
    }
    return 0;
}
