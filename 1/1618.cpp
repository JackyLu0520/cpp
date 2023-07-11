#include<iostream>
using namespace std;
int x1,x2,x3;
float a1,b,c;
bool f1,f2=true;
int a[10],i;
int main()
{
	cin>>a1>>b>>c;
    for (x1=100; x1<=1000/3; x1++)  ///枚举
    {
        x2=x1*(b/a1);
		x3=x1*(c/a1);///生成
        f1=true;
		for (i=0; i<=9; i++) 
			a[i]=1; /// 判断
        a[x1/100%10]--;
        a[x1/10%10]--;
        a[x1/1%10]--;
        a[x2/100%10]--;
        a[x2/10%10]--;
        a[x2/1%10]--;
        a[x3/100%10]--;
        a[x3/10%10]--;
        a[x3/1%10]--;
        for (i=1; i<=9; i++) 
			if (a[i]==1) f1=false; ///!!!判重
        if (f1) 
		{ 
			cout<<x1<<' '<<x2<<' '<<x3<<endl;
			f2=false;
		}
    }
    if(f2)
		cout<<"No!!!"; 
    return 0;
}//P1618
