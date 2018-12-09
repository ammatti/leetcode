#include <iostream>
#include <string>

using namespace std;

class Solution {

public:

  string numberToWords(int num) {
    // num < 2^31-1
    string units[] = {"", "Thousand", "Million", "Billion"};
    string result = "";
    int localNumber = num;
    if (localNumber == 0) {
      result = "Zero";
    }
    // 0 <= num < 2^31-1, from the end to the head
    for (int i = 0; i < 4; i++) {
        if ((localNumber %1000) == 0) {
            localNumber = localNumber/1000;
             //debug
             //cout<<1<<": local="<<localNumber<<endl;;
        } else {
            result = convertHundred(localNumber%1000)+" "+units[i]+" "+result;
            //debug
            //cout<<"result="<<result<<endl;
            localNumber = localNumber/1000;
        }
    }
    return rtrim(result);
  }

  string convertHundred(int number){
    string ans = "";
    int temp = 0;
    string ten[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string hundred[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string twenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    if(number > 0){
       temp = number /100;
       if (temp>0){
          ans = ten[temp]+" Hundred"+ans;
       }
       temp = number%100;
       if(temp>=10 && temp<20){
          if(!ans.empty()) ans= ans+" ";
          ans = ans+twenty[temp%10];
       }else if(temp>=20){
          if(!ans.empty()) ans= ans+" ";
          int local = temp/10;
          ans = ans+ hundred[local-1];
          local = temp%10;
          if(local > 0){
          ans= ans+" ";
          ans = ans+ten[local];
          }
       }else{
         //temp < 10
         if(!ans.empty()) ans= ans+" ";
         
         if(temp> 0) ans = ans+ten[temp];
       }
    }
    return ans;
  }

  string rtrim(const string& s)
{
        const string WHITESPACE = " \n\r\t\f\v";
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

};

int main() { 

Solution s;
string ans = s.numberToWords(1001);
cout<<ans<<endl;
return 0;

}
