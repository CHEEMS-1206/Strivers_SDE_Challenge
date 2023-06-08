/// Ques 1 --- Two sum
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(target - nums[j] == nums[i]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// ============================================================================================== ///

/// Ques 2 --- 4sum
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                for(int k=j+1; k<n-1; k++){
                    for(int l=k+1; l<n; l++){
                        if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + 
                        (long long)nums[l] == target){
                            set.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Longest common subsequence
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int longest = 1;
        unordered_set<int> st;
        for(auto x : nums){
            st.insert(x);
        }
        for(auto s : st){
            if(st.find(s-1) == st.end()){
                int count = 1;
                int x = s;
                while(st.find(x+1) != st.end()){
                    count++;
                    x = x+1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

// ============================================================================================== ///

/// Ques 4 --- Longest Substring Without Repeating Characters
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;  
        unordered_map<char,int> m;   
        int i=0,j=0,ans=INT_MIN; 
        while(j<s.length())   
        {
            m[s[j]]++;
            if(m.size()==j-i+1) 
            {
                ans = max(ans,j-i+1); 
            }
            else if(m.size()<j-i+1) 
            {
                while(m.size()<j-i+1)
                {
                    m[s[i]]--; 
                    if(m[s[i]]==0) 
                    {
                        m.erase(s[i]);
                    }
                    i++;  
                }
            }
            j++;  
        }
        return ans;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Length of the longest subarray with zero Sum
/// ->> Codestudio
-
/// ->> GFG 
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}

// ============================================================================================== ///

/// Ques 6 --- Count the number of subarrays with given xor K
/// ->> Codestudio
-

/// ->> Leetcode 
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

// ============================================================================================== ///