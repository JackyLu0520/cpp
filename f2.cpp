#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	FILE *fin,*fout; 
	fin=fopen("in.txt","rb");
	fout=fopen("out.txt","wb");
	int t,s;
	while(fscanf(fin,"%d",&t)==1)
		s+=t;
	fprintf(fout,"%d",s);
	fclose(fin);
	fclose(fout);
	return 0;
}

