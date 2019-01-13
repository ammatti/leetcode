//https://en.cppreference.com/w/cpp/utility/tuple
//clang++ -std=c++14 373_k_smallest_sum.cpp

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:

  static bool sorttuple(const tuple<int,int,long> &a,
                 const tuple<int,int,long> &b) {

    return (get<2>(a) < get<2>(b));
  }

public:
  vector< pair<int, int> > kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
    vector< pair<int, int> > answer;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int total = n1 * n2;
    if (k <= 0 || n1<=0 || n2<=0) {
      return answer;
    } else if (k == 1) {
      pair<int, int> temp = make_pair(nums1[0], nums2[0]);
      answer.push_back(temp);
    } else if (k < total) {
      vector<tuple<int, int, long>> content;
      pair<int, int> temp;
      tuple<int, int, long> item;
      vector<int>::iterator it1;
      vector<int>::iterator it2;
      for (it1 = nums1.begin(); it1 != nums1.end(); it1++) {
        for (it2 = nums2.begin(); it2 != nums2.end(); it2++) {
          item = make_tuple(*it1, *it2, *it1 + *it2);
          content.push_back(item);
        }
      }
      sort(content.begin(), content.end(), sorttuple);
      vector<tuple<int,int,long>>::iterator it3;
      int index = 0;
      for(it3 = content.begin(); it3!=content.end();it3++){
         index = index + 1;
         temp.first = get<0>(*it3);
         temp.second = get<1>(*it3);
         answer.push_back(temp);
         if(index == k) break;
      }      
    } else {
      // k>=total, return all combinations
      pair<int, int> temp;
      vector<int>::iterator it1;
      vector<int>::iterator it2;
      for (it1 = nums1.begin(); it1 != nums1.end(); it1++) {
        for (it2 = nums2.begin(); it2 != nums2.end(); it2++) {
          temp.first = *it1;
          temp.second = *it2;
          answer.push_back(temp);
        }
      }
    }
    return answer;
  }
};

int main() {
  Solution sol;
  int arr1[] = {1, 2, 3};
  int arr2[] = {4, 5, 6};
  vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
  vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
  int k = 3;
  vector< pair<int, int> > ans = sol.kSmallestPairs(input1, input2, k);
  vector< pair<int, int> >::iterator it;
  for (it = ans.begin(); it != ans.end(); it++) {
    cout << it->first << "," << it->second << endl;
  }
  return 0;
}

