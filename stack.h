struct stack{
	string a;
	int top;
	void push(char x){
		a[++top]=x;
	}
	char pop(){
		top--;
	}
};
