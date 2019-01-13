#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getHash(string &str){
        int hash_value;
        int alphbeta[27] ={0};
        int index, temp=0;
        for (int i =0; i<str.length(); i++){
            index = str.at(i) - 'a';
            alphbeta[index] = alphbeta[index]+1;
        }
        for(int j=0;j<27;j++){
            //cout<<alphbeta[j]<<endl;
            temp = alphbeta[j]*(j+1);
            hash_value = hash_value+temp;
        }
        return hash_value;
    }
    
    bool isSameGroup(string &a, string &b){
        //value of alphbeta[0] means value of 'a'
        int alphbeta[27] = {0};
        bool isGroup;
        return isGroup;
    }

    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        //hash map <string_hash, group_id>
        vector<string>::iterator it;
        //hash<string> str_hash;
        for(it = strs.begin(); it != strs.end(); it++){
	    //cout<< (*it) << str_hash(*it)<<endl;
            int temp = getHash(*it);
            cout<<temp<<endl;
        }
        //string a = "nat";
        //int temp = getHash(a);
        //cout<<temp<<endl;
        return ans;
    }
};



int main(){
    char const *vinit[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> input(vinit, vinit+6);
    /*
    vector<string>::iterator it;
    for(it = input.begin(); it != input.end(); it++){
        cout<< (*it) <<endl;
    }
    */
    Solution sol;
    sol.groupAnagrams(input);
    return 0;
}
