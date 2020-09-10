#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <stack>
#include <vector>
#include "mystack.h"
#include "Pair.h"
using namespace std;
//todo else push for single number in bracket
float expression_value(string str)
{
  Pair priority;
  priority.insert('^',3);
  priority.insert('*',2);
  priority.insert('/',2);
  priority.insert('%',2);
  priority.insert('+',1);
  priority.insert('-',1);
  priority.insert('(',0);
  priority.insert('{',0);
  priority.insert('[',0);

  
  
 
  
  
  bool floating = false;
  bool valNotPushed=true;
  float placeVal = 0.1;

  mystack<char> op_stack;
  mystack<float> val_stack;
  mystack<char> op_vector;
  mystack<float> val_vector;

 

  float val = 0;
  for (int i = 0; str[i]; i++)
  {   
    if (str[i] >= '0' && str[i] <= '9')
    {
      valNotPushed=true;
      if(floating){
        int dec =str[i]-'0';
        float num =dec*placeVal;
        val=val+num;
        placeVal=placeVal/10;
      }
      else
      {
      val = val * 10 + str[i] - '0';
      }
    
    }

    else if (str[i] == '.'){floating = true;}


    else if(str[i]=='('||str[i]=='{'||str[i]=='['){
        op_stack.push(str[i]);
        val=0;
    }
    else if(str[i]==')'||str[i]=='}'||str[i]==']'){
        //FLOATING VALUE AND PLACE VALUE floating=false;
        //placeVal=0.1;
        val_stack.push(val);
        valNotPushed=false;
        char lookingFor=')';
        if(str[i]==')'){lookingFor='(';}else if(str[i]=='}'){lookingFor='{';}else{lookingFor='[';}
       
        while (val_stack.size()>=2 && !op_stack.empty() && (op_stack.top()!= lookingFor))
        {
           
          float num1, num2;
          num2 = val_stack.top();
          val_stack.pop();
          
          num1 = val_stack.top();

          val_stack.pop();
          

          if (op_stack.top() == '+')
          {
            val_stack.push(num1 + num2);
            
          }

          else if (op_stack.top() == '-')
          {
            val_stack.push(num1 - num2);
            
          }

          else if (op_stack.top() == '*')
          {
            val_stack.push(num1 * num2);
           
          }

          else if (op_stack.top() == '/')
          {
            val_stack.push(num1 / num2);
          
          }

          else if(op_stack.top()=='%')
          {
            val_stack.push((int)num1 % (int)num2);
          }

          
         
          op_stack.pop();
          
        }
        
        op_stack.pop();
       }
    

    else
    {
      floating=false;
      placeVal=0.1;
      
      if (op_stack.empty())
      { 
        if(valNotPushed){val_stack.push(val);}
        op_stack.push(str[i]);
      }
      else if (priority.getVal(op_stack.top()) < priority.getVal(str[i])) // priority of open braces should be minimum so all numbers are stacked over it
      {
        if(valNotPushed){val_stack.push(val);}
        op_stack.push(str[i]);
      }
      else
      { 
        if(valNotPushed){val_stack.push(val);}
        

        while (!op_stack.empty() && priority.getVal(op_stack.top()) >= priority.getVal(str[i]))
        {

          float num1, num2;
          num2 = val_stack.top();
          val_stack.pop();
          num1 = val_stack.top();
          val_stack.pop();

          if (op_stack.top() == '+')
          {val_stack.push(num1 + num2);}

          else if (op_stack.top() == '-')
          {val_stack.push(num1 - num2);}

          else if (op_stack.top() == '*'){val_stack.push(num1 * num2);}

          else if (op_stack.top() == '/'){val_stack.push(num1 / num2);}

          else {val_stack.push((int)num1 % (int)num2);}

        op_stack.pop();
        }

        valNotPushed=false;
        op_stack.push(str[i]); 
      }
      val = 0;
    }
  }
  if(valNotPushed){val_stack.push(val);}
  

  while (!op_stack.empty() && val_stack.size()>=2)
  { 
    float num1, num2;
    num2 = val_stack.top();
    val_stack.pop();
    num1 = val_stack.top();
    val_stack.pop();

    if (op_stack.top() == '+') {val_stack.push(num1 + num2);}

    else if (op_stack.top() == '-') { val_stack.push(num1 - num2);}
    
    else if (op_stack.top() == '*') {val_stack.push(num1 * num2);}

    else if (op_stack.top() == '/') {val_stack.push(num1 / num2);}
    
    else {val_stack.push((int)num1 % (int)num2);}
    
    op_stack.pop();
  
  }
  return val_stack.top();
}

int main()
{
  float answer = expression_value("(6)*(((9+6/3-5)+9)/15)");
  cout << answer;
  return 0;
}