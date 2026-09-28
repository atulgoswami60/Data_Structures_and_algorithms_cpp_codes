#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
char stackArr[MAX]; // for parentheses and ops
int top = -1;

void push(char c){
	top++; 
	stackArr[top] = c;
}
char pop(){
	char popvalue;
	popvalue = stackArr[top];
	top--;
	return popvalue;
}
bool isEmpty(){
	return (top == -1);
}
int precedence(char c){
	if(c == '^') return 3;
	else if(c == '*'|| c == '/'||c == '%') return 2;
	else if(c == '+'||c == '-') return 1;
	else return -1;
}
void infixToPostfix(char infix[], char postfix[]){
	int k = 0; // index for postfix
	for(int i=0; i<strlen(infix);i++){
		char ch = infix[i];
		//if operand, add to postfix
		if((ch >= 'a' && ch <= 'z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
			postfix[k] = ch;
			k++;
		}
		//if opening parenthesis, push to stack
		else if(ch=='('){
			push(ch);
		}
		else if(ch == ')'){
			while(!isEmpty() && stackArr[top] != '('){
				postfix[k] = pop();
				k = k + 1;
			}
			pop(); // remove '('
		}
		// if operator
		else{
			while(!isEmpty() && precedence(stackArr[top]) >= precedence(ch)){
				postfix[k] = pop();
				k++;
			}
			push(ch);
		}
	} // nothing left to scan in Q
	// pop remaining operators
	while(!isEmpty()){
		postfix[k] = pop();
		k = k+1;
	}
	postfix[k] = '\0'; // end of string
}

int main(){
	char infix[MAX], postfix[MAX];
	cout<<"Enter infix expression: ";
	cin>>infix;
	infixToPostfix(infix, postfix);
	cout<<"postfix expression: "<<postfix<<endl;
	
	return 0;
}
