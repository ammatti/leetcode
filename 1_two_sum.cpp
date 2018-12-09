#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
	//1. sort the array
        vector<int> result;
        vector<int> nums_ori = nums;
        std:sort(nums.begin(),nums.end());
	//2. use two index, one from the head, the other from the tail
             //compute head+tail
             //(if head == tail return fail)
	     //if v[head]+v[tail]>target, tail--
             //else if v[head]+v[tail]<target, head++
             //else (v[head]+v[tail] == target)
       int size = nums.size();
       int i = 0;
       int j = size-1;
       cout<<"j="<<j<<endl;
       while(true){
		if(i == j){
			cout<<"failed case"<<endl;
			break;
		}
		else if(nums.at(i)+nums.at(j)>target){
			j--;
			cout<<"j--"<<endl;
			continue;
		}else if(nums.at(i)+nums.at(j)<target){
			i++;
			cout<<"i++"<<endl;
			continue;
		}else{
			vector<int>::iterator iter1=std::find(nums_ori.begin(),nums_ori.end(),nums.at(i));
			vector<int>::iterator iter2=std::find(nums_ori.begin(),nums_ori.end(),nums.at(j));
			int start = std::distance(nums_ori.begin(), iter1);
                        cout<<start<<endl;
			
			int end = std::distance(nums_ori.begin(), iter2);
			while(end == start){
				vector<int>::iterator iter3 = iter3=std::find(++iter2, nums_ori.end(),nums.at(j));
				end = std::distance(nums_ori.begin(), iter3);
                        }
			cout<<end<<endl;
                        result.push_back(start);
                        result.push_back(end);
			return result;
		}

	}
    }
};


int main(void){
        int arr[] = {3, 3};
	vector<int> test(arr, arr+sizeof(arr)/sizeof(int)); 
        Solution sol;
        vector<int> ans = sol.twoSum(test, 6);
        //
	for (auto i = ans.begin(); i != ans.end(); ++i)
		std::cout << *i << ' ';
        cout<<endl;
	return 0;
}
