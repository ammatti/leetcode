/**
0. string tokenize
1. convert infix expression to postfix/prefix expression
        -empty
        -not right expression format
        -big dicimal
2. evaluate expression
        -postfix (scan from left to right)
        -prefix (scan from right to left)
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair <int,string> token;

class EvaluateEXP {

  static const int NUMBER = 0, OPERATOR_1 = 1, OPERATOR_2 = 2, PARENTHESIS = 3,
                   OTHERS = 4;

private:
  vector<token> infix_to_postfix(vector<token> infix);
  vector<token> infix_to_prefix(vector<token> infix);
  string big_add(string first, string second);
  string big_subtract(string first, string second);
  string big_multiply(string first, string second);
  string big_divide(string first, string second);
  string big_mod(string first, string second);

public:
  string prefix_calc(vector<token> pre_exp);

  string postfix_calc(vector<token> post_exp);
};

vector<token> EvaluateEXP::infix_to_postfix(vector<token> infix) {
  vector<token> result;
  token current;
  token op_token;
  int token_type;
  vector<token> op_buffer;
  for (int i = 0; i < infix.size(); i++) {
    current = infix[i];
    token_type = current.first;
    switch (token_type) {
    case NUMBER:
      result.push_back(current);
      break;
    case OPERATOR_1:
    case OPERATOR_2:
      if (op_buffer.size() > 0) {
        op_token = op_buffer.back();
        // compare priority
        if (op_token.first <= current.first) {
          result.push_back(op_token);
          op_buffer.pop_back();
          op_buffer.push_back(current);
        } else {
          op_buffer.push_back(current);
        }
      } else {
        op_buffer.push_back(current);
      }
      break;
    case OTHERS:
      // TODO: deal with parenthesis
      break;
    }
  }
  // flush op_buffer
  while (op_buffer.size() > 0) {
    op_token = op_buffer.back();
    result.push_back(op_token);
    op_buffer.pop_back();
  }
  return result;
}

string EvaluateEXP::big_add(string first, string second){}
string EvaluateEXP::big_add(string first, string second){}
string EvaluateEXP::big_add(string first, string second){}
string EvaluateEXP::big_add(string first, string second){}
string EvaluateEXP::big_add(string first, string second){}

string EvaluateEXP::postfix_calc(vector<token> infix) {
  string answer;
  vector<token> buffer;
  vector<token> postfix;
  postfix = infix_to_postfix(infix);

  for (int i = 0; i<postfix.size(); i++){
	//cout<<postfix[i].first<<" "<<postfix[i].second<<endl;
        
	}
  
  return answer;
}

class ExpressionOP {

  static const int NUMBER = 0, OPERATOR_1 = 1, OPERATOR_2 = 2, PARENTHESIS = 3,
                   OTHERS = 4;

private:
  int get_char_type(char c) {
    if (c >= '0' && c <= '9') {
      return NUMBER;
    } else if (c == '*' || c == '/' || c == '%') {
      return OPERATOR_1;
    } else if (c == '+' || c == '-') {
      return OPERATOR_2;
    } else if (c == '(' || c == ')') {
      return PARENTHESIS;
    } else {
      return OTHERS;
    }
    return 0;
  }

public:
  vector<token> convert_exp(string input) {
    vector<token> token_list;
    string buffer;
    token temp;
    bool in_number = false;

    for (int i = 0; i < input.size(); i++) {
      char c = input[i];
      int type = get_char_type(input[i]);
      switch(type){
		case NUMBER:
			buffer+=c;
			in_number = true;
			break;
		case OPERATOR_1:
			if(in_number){
                                temp = make_pair(NUMBER,buffer);
				token_list.push_back(temp);
				buffer="";
				in_number = false;
			}
                        temp = make_pair(OPERATOR_1, input.substr(i,1));
			token_list.push_back(temp);
                        break;
		case OPERATOR_2:
			if(in_number){
                                temp = make_pair(NUMBER, buffer);
				token_list.push_back(temp);
				buffer="";
				in_number = false;
			}
                        temp = make_pair(OPERATOR_2, input.substr(i,1));
			token_list.push_back(temp);
			break;
		default:
			if(in_number){
				temp = make_pair(NUMBER, buffer);
				token_list.push_back(temp);
				buffer="";
				in_number = false;
			}
			break;
	}
    }

	if(in_number){
		temp = make_pair(NUMBER, buffer);
		token_list.push_back(temp);
		buffer="";
		in_number = false;
		}
    return token_list;
  }
  void display(string str) { cout << str << endl; }
};

int main() {
  ExpressionOP m;
  EvaluateEXP calc;

  vector<token> tokens;
  string str1 = "Enter Input Expression:";
  string input;
  string answer;
  m.display(str1);
  //getline(cin, input);
  input = "1+3*9";
  m.display(input);
  tokens = m.convert_exp(input);
  for (int i = 0; i < tokens.size(); i++) {
	cout<<tokens[i].first<<" "<<tokens[i].second<<endl;
  }
  answer = calc.postfix_calc(tokens);
  cout<<"answer = "<<answer<<endl;
  return 0;
}

