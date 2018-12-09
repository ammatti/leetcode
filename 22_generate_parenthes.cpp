#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateAllParenthesis(int n) {
	vector<string> output_permutation;
	vector<char> input_str;
        for (int i=0; i<n; i++){
		input_str.push_back('(');
                input_str.push_back(')');
	}
        /* debug
        vector<char>::iterator it;
        for (it = input_str.begin(); it != input_str.end(); it++){
		cout<<*it;
	}
        cout<<endl;
        */

        //gen all permutation
        string str(input_str.begin(),input_str.end()); 
        char * cstr = new char [str.length()+1];
        strcpy(cstr, str.c_str());
        genStr(cstr, 0, input_str.size(), &output_permutation);
        delete[] cstr;
        /** for debug
        cout<<"size="<<output_permutation.size()<<endl;
        for(int i=0;i<output_permutation.size();i++){
	    cout<<output_permutation.at(i)<<endl;
	}
        **/
        return output_permutation;
    }
 
    void swap (char* first, char* second){
        char temp = *first;
        *first = *second;
        *second = temp;
    }
   
    void genStr(char* str, int start, int length, vector<string> *output){
        if (start == length-1){
            /** for debug
            cout<<str<<endl;
            **/
            output->push_back(str);
            //return str;
	} 
        else{
            for (int i=start; i<length; i++){
                if(isSwap(str, start, i)){
                    swap(&str[start], &str[i]);
                    genStr(str, start+1, length, output);
                    swap(&str[start], &str[i]);
                }
            }            

        }
        //avoid warning
        //return str;
    }
    bool isValid(string s){
         bool valid = true;
         stack<char> temp;
         for (int i=0;i<s.length();i++){
             if(s.at(i) == ')'){
                if(!temp.empty()){
                    temp.pop();
                } else {
                    valid = false;
                    return valid;
                }
             }else if(s.at(i) == '('){
                 temp.push('(');
             }else{
                 //error handling
             }
         }
         return valid;
    }

    vector<string> genSol(vector<string> all){
	string s;
        vector<string> sol;
        for(int i =0; i<all.size();i++){
            s = all.at(i);
            if (isValid(s)){
                sol.push_back(s);
            }
        }
        return sol;
    }
    
    bool isSwap(char* str, int start, int end){
        bool isOk = true;
        for(;start < end; start++){
            if(str[start] == str[end]){
             isOk = false;
             return isOk;
            }
        }
        return isOk;
    }

};


int main(){
    Solution s;
    vector<string> output_permutation = s.generateAllParenthesis(3);
    vector<string> solution = s.genSol(output_permutation);
    for(int i =0; i<solution.size();i++){
        cout<<solution.at(i)<<endl;
    }
    return 0;
}
