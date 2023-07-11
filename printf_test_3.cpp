#include<cstdio>
int main(){
	double i=123.456789;
	char s[]="The teacher was late.";
	printf("%f\n",i);
	printf("%15f\n",i);
	printf("%8.2f\n",i);
	printf("%-8.2f\n",i);
	printf("%s\n",s);
	printf("%10s\n",s);
	printf("%20s\n",s);
	printf("%-20s\n",s);
	printf("%20.2s\n",s);
	printf("%-20.2s\n",s);
	return 0;
}
