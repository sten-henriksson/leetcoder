// CMakeProject2.cpp : Defines the entry point for the application.

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#include "leetcode.h"
vector<int> twoSum(vector<int> nums, int target)
{
	unordered_map<int, int> m;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{

		int valueneeded = target - nums[i];
		cout << valueneeded << endl;
		if (m.find(valueneeded) != m.end())
		{
			cout << nums[i] << endl;

			cout << m[valueneeded] << endl;
			result.push_back(m[valueneeded]);
			result.push_back(nums[i]);
			break;
		}
		else
		{
			m.insert({nums[i], i});
		}
	}
	return result;
}

bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;

	unordered_map<char, int> smap;
	unordered_map<char, int> tmap;

	for (int i = 0; i < s.size(); i++)
	{
		smap[s[i]]++;
		tmap[t[i]]++;
	}
	cout << "asd" << endl;

	for (int i = 0; i < smap.size(); i++)
	{
		if (smap[i] != tmap[i])
			return false;
	}
	return true;
}

unordered_map<char, int> getMap(string s)
{
	unordered_map<char, int> smap;
	for (int i = 0; i < s.size(); i++)
	{
		smap[s[i]]++;
	}
	return smap;
}

bool isAnagram(unordered_map<char, int> s, unordered_map<char, int> t)
{
	if (s.size() != t.size())
		return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (t[i] != t[i])
			return false;
	}
	return true;
}

// creates a "hash"
string getKey(string str)
{
	vector<int> count(26);
	for (int j = 0; j < str.size(); j++)
	{
		count[str[j] - 'a']++;
	}

	string key = "";
	for (int i = 0; i < 26; i++)
	{
		key.append(to_string(count[i] + 'a'));
	}
	return key;
}

// add each strs to map with hash as key and index in string as value
// loop over as its already orderd by buckets?
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	unordered_map<string, vector<string>> m;
	for (int i = 0; i < strs.size(); i++)
	{
		string key = getKey(strs[i]);
		m[key].push_back(strs[i]);
	}
	vector<vector<string>> result;
	for (const auto &n : m)
	{

		result.push_back(n.second);
	}
	return result;
}

/*
create hashmaps
sort arr index as key in map
get bucketsize for each key

*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
			cout <<"a"<<it->first << '\n';
			cout <<"b"<<it->second << '\n';
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		int findex = 1;
		vector<int> result(n,1);
		for (int i = 0; i < n; i++)
		{
			result[i] = findex;
			findex = findex * nums[i];
		}
		int bindex = 1;
		for (int i = n - 1; i >= 0; i--) {
			result[i] = result[i] * bindex;
			bindex = bindex * nums[i];
		}
		for (int i = 0; i < n; i++)
		{
			cout << result[i] << '\n';
		}
		return result;
	}
int main()
{
	std::vector<int> v = {1,2,3,4,4,4};
	productExceptSelf(v);
	std::cout << '\n';
	return 0;
}
