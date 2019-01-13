#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.empty()) {
      return true;
    } else if((s.length()%2) != 0){
      return false;
    } else {
      //create a stack
      vector<char> stack;
      char temp;
      char popout;
      //push left parenthese to stack
      //and pop it when right patenthese
      //if not match return false
      for (int i=0; i<s.length();i++){
         temp = s.at(i);
         if(temp == '(' || temp == '[' || temp =='{'){
            stack.push_back(temp);
         }
         else if(temp == ')' || temp == ']' || temp =='}'){
            if(stack.size() == 0){
               return false;
            }else{
               popout = stack.back();
               stack.pop_back();
               switch(temp){
                   case ')':
                      if(popout != '(') return false;
                      break;
                   case ']':
                      if(popout != '[') return false;
                      break;
                   case '}':
                      if(popout != '{') return false;
                      break;
                   default:
                      return false;
               }
            }
         }
         else{
            //error
            return false;
         }
      }//for
      if(stack.size() !=0) {return false;}
      else {return true;}
    }
  }
};

int main() { 

string input = "((}){}{}";
Solution s;
bool ans = s.isValid(input);
cout<<ans<<endl;
return 0;
}
