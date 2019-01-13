#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
 int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int ans = 0;
        int temp = 0;
        int current_buy = 0;
        int current_sell = 0;
        int p_buy = 65535;
        int p_sell =0;
        for(int i=0; i<prices.size();i++){
          for(int j=i+1;j<prices.size();j++){
             current_sell = prices.at(j);
             current_buy =  prices.at(i);
             //cout<<current_buy<<"/"<< current_sell<<endl;
             //if((current_buy > p_buy) || (current_sell < p_sell)) { continue; }
             temp = current_sell - current_buy;
             if(temp > ans) {
                  //cout<<"ans="<<temp<<endl;
                  ans = temp;
                  p_buy = current_buy;
                  p_sell = current_sell;
             }
          }
        }
        return ans;
    }
};


int main(){

Solution s;
//vector<int> input = {7, 1, 5, 3, 6, 4};
//vector<int> input = {7, 6, 4, 3, 1};
vector<int> input = {3,3,5,0,0,3,1,4};
int result = s.maxProfit(input);
cout<<result<<endl;

return 0;
}
