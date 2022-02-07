#include<stdio.h>
#include<string.h>
char OperatorStack[10];
char OperandStack[10];

int topOR=-1;
int initOP=-1;
char * InfixToPostfix(char * );
int OperatorPrecedence(char);
int IsORStackEmpty();
int main()
{
    char exp[10],newexp[10];
    printf("Enter the Infix Expression:");
    scanf("%s",&exp);
    printf("Infix Expression\n");
    printf("%s",exp);
    strcpy(newexp,InfixToPostfix(exp));
    printf("\nPostfix Expression\n");
    printf("%s",newexp);
    return 0;
}


char * InfixToPostfix(char * Expression)
{   int i;
        i=0;
        char NewExpression[10];
    while(Expression[i]!='/0')
    {
        if(Expression[i]=='+' || Expression[i]=='-' || Expression[i]=='*' || Expression[i]=='/' || Expression[i]=='(' || Expression[i]==')')
        {
              if(IsORStackEmpty())
              {
                  topOR++;
                  OperatorStack[topOR]=Expression[i];
              }
               
              else if(OperatorPrecedence(Expression[i])>=OperatorPrecedence(OperatorStack[topOR]))
              {
                  topOR++;
                  OperatorStack[topOR]=Expression[i];
              }
              
              else if(OperatorPrecedence(Expression[i])<OperatorPrecedence(OperatorStack[topOR]))
              {
                  initOP++;
                  OperandStack[initOP]=OperatorStack[topOR];
                  topOR--;
                  
              }
               
               
              else if(Expression[i]=='(')
              {
                  topOR++;
                  OperatorStack[topOR]='(';
              }
              
              else if (Expression[i]==')')
              {
                  while( !IsORStackEmpty() && OperatorStack[topOR]!='(')
                  {
                      initOP++;
                      OperandStack[initOP]=OperatorStack[topOR];
                      topOR--;
                      
                  }
              }
              
              
              
        }
        else
        {
            OperandStack[++initOP]=Expression[i];
        }
        
        i++;
    }
    
    return OperandStack;
}


int OperatorPrecedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 3;
        break;
    }
}

int IsORStackEmpty()
{
    if(topOR==-1)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}
