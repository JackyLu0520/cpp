#include<iostream>
using namespace std;
int o,n,e,t,w,one,two;
int a[10],i;
bool b;
int main()
{
        for(o=1; o<=4; o++)
            for(n=0; n<=9; n++)
                for(e=0; e<=9; e++)
                    for(t=1; t<=9; t++)
                        for(w=0; w<=9; w++)
      						{
          						one=o*100+n*10+e;
          						two=t*100+w*10+o;
          						if(two==one*2)
          						{
              						b=true;//����
              						for(i=0; i<=9; i++) a[i]=1; //ÿ��������������һ��
              						a[o]--;a[n]--;a[e]--;a[t]--;a[w]--;
             						for(i=0; i<=9; i++) if(a[i]<0) b=false; 
									//���ĳ�����ֵĿ��ô���С��0��˵�������˲�ֹһ��
             						if(b)cout<<one<<'+'<<one<<'='<<two<<endl;
          						}
      						}
    return 0;
}

