#include <iostream>
using namespace std;
int t[10];
int main()
{
	for (int h=1; h<=9; h++)
		for (int a=1; a<=9; a++)
		{
			int ahhaah=h*11001+a*100110;
			int ha=h*10+a;
			if (ahhaah%ha==0)
			{
				int joke=ahhaah/ha;
				int j=joke/1000%10;
				int o=joke/100%10;
				int k=joke/10%10;
				int e=joke/1%10;

				///�ж� j,o,k,e,h,a������ͬ
				for (int i=0; i<=9; i++) t[i]=1; ///��Ҷ���1
				bool b=1; ///��ʾû�ҵ��ظ���
				t[j]--,t[o]--,t[k]--,t[e]--,t[h]--,t[a]--;  ///ÿ���˶���1
				for (int i=0; i<=9; i++) if (t[i]<0) b=0; ///���˼���2������ С��0
				if (b==1) cout<<ahhaah<<'/'<<joke<<'='<<ha<<endl;
			}
		}
	return 0;
}

