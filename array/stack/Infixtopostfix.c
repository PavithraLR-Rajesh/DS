//INFIX TO POSTFIX
#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 30
int stack[size];
int top=-1;
int priority(char symbol);
int evalpost();
void infixtopostfix();
int push(int symbol);
int pop();
char postfix[size],infix[size];
int isempty();
void main()
{
int result;
    printf("Enter the infix array:\n");
    scanf("%s",infix);
    infixtopostfix();
	printf("Postfix:%s",postfix);
	result=evalpost();
	printf("Value of postfix expression:%d\n",result);
    
}
void infixtopostfix(){
    int i,p=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch (symbol)
        {
            case '(':push(symbol);
                       break;
            case ')':while((next=pop())!='(')
                     postfix[p++]=next;
                     break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'%':
            case'^': while(isempty()==0&&priority(stack[top])>=priority(symbol))
            postfix[p++]=pop();
            push(symbol);
            break;
            default:postfix[p++]=symbol;
        }
    }
    while(isempty()==0)
    postfix[p++]=pop();
    postfix[p]='\0';
    
    
}
int priority(char symbol){
    switch(symbol){
        case'(':return 0;
        case'+':
        case'-':return 1;
        case'/':
        case'*':
        case'%':return 2;
        case'^':return 3;
        default:return 0;
         }
    
}
int evalpost(){
    int a,b,temp,result;
    int i;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]<= '9' && postfix[i]>= '0')
        push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i]){
                case'+':temp=b+a;
                break;
                case'-':temp=b-a;
                break;
                case'*':temp=b*a;
                break;
                case'/':temp=b/a;
                break;
                case'%':temp=b%a;
                break;
                case'^':temp=pow(b,a);
                break;
                
            }
			push(temp);
        }
        
        
    }
    result=pop();
    return result;
}
int push(int symbol){
    if(top==size-1){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top]=symbol;
    }
	return(symbol);
}

int isempty() {
    if (top == -1) {
       
        return 1;
    } else {
        return 0;
    }
}  



int pop(){
	int y;
	if(top==-1){
    printf("Stack is empty");
	  return '\0';}
    else{
        
        return(stack[top--]);
    }
    }