#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void swap(vector<int> &nums, int a, int b) {
    int temp = nums.at(a);
    nums.at(a) = nums.at(b);
    nums.at(b) = temp;
  }

  void moveZeroes(vector<int> &nums) {
    int zero_index = -1;
    int int_index = -1;

    if (nums.empty())
      return;

    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i) == 0) {
        if (zero_index == -1)
          zero_index = i;
      } else {
        int_index = i;
      }
      if ((zero_index > -1) && (zero_index < int_index)) {
        swap(nums, zero_index, int_index);
        zero_index = zero_index + 1;
        int_index = zero_index;
      }
    }
  }
};

int main() {

  Solution s;
  int numbers[] = {0, 1, 2, 0, 3, 8};
  vector<int> input(numbers, numbers + 6); ;
  s.moveZeroes(input);
  for (int i =0; i<input.size();i++){
   cout<<input.at(i)<<endl;
  }
  return 0;
}

