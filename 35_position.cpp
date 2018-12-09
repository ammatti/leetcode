#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int result = 0;
    vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); it++) {
      // cout << *it << endl;
      if (*it == target) {
        result = distance(nums.begin(), it);
        return result;
      } else if (*it > target) {
        result = distance(nums.begin(), it);
        return result;
      } else {
      }
    }
    result = distance(nums.begin(), nums.end());
    return result;
  }
};

int main() {
  Solution sol;
  int input[] = {1, 3, 5, 6};
  vector<int> numbers(input, input + 4);
  int ans = sol.searchInsert(numbers, 5);
  cout << ans << endl;
  return 0;
}

