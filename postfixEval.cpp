#include <iostream>
using namespace std;

const int MAX = 100;   
int stackArr[MAX];
int top = -1;

void push(int x){
	top++; stackArr[top] = x;
}

int pop(){
	int popvalue = stackArr[top];
	top--; return popvalue;
}

int main(){
	char pexp[MAX];
	cout<<"Enter the postfix expression (only with single digit number): ";  // 532+*
	cin>>pexp;
	int i = 0;
	while(pexp[i] != '\0'){
		char ch = pexp[i];
		//if it is digit (operand)
		if(ch >= '0' && ch <= '9'){ //ASCII number of '0' is 48 and '9' = 57
			push(ch - '0');
		// if it is operator, as we have only operand and operator in postfix expression	
		}else{
			int A = pop();
			int B = pop();
			int result;
			if(ch == '+') result = B+A;
			else if(ch == '-') result = B-A;
			else if(ch == '*') result = B*A;
			else if(ch == '/') result = B/A;
			push(result);
		}
		i++;
	}
	cout<<"Result = "<<pop()<<endl;
	
	
	
	return 0;
}
