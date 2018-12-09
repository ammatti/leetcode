#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int result = 0;
    int left = 0;
    int temp = 0;
    int right = height.size() -1;
    while (left < right) {
      if (height.at(left) < height.at(right)) {
        temp = height.at(left) * (right - left);
        left++;
      } else {
        temp = height.at(right) * (right - left);
        right--;
      }
      if (result < temp) {
        result = temp;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  int input[] = {1, 3, 5, 6};
  vector<int> numbers(input, input + 4);
  int ans = sol.maxArea(numbers);
  cout << ans << endl;
  return 0;
}

