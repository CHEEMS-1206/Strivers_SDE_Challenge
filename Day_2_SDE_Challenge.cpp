/// Ques 1 --- Rotate Matrix
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        
        for(int i=0; i<=n-1; i++){
            for(int j=i+1; j<=n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0; i<=n; i++){
            int j=0, cols=n;
            while(j<=cols){
                swap(matrix[i][j++],matrix[i][cols--]);
            }
        }
    }
};

// ============================================================================================== ///

/// Ques 2 --- Merge Subintervals
/// ->> Codestudio
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
            }else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
/// ->> Leetcode 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
            }else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Merge two sorted arrays
/// ->> Codestudio
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> final;
    int i=0,j=0;
    while(i<m && j<n){
        if(arr1[i] <= arr2[j]){
            final.push_back(arr1[i++]);
        }else{
            final.push_back(arr2[j++]);
        }
    }
    while(i<m){
        final.push_back(arr1[i++]);
    }
    while(j<n){
        final.push_back(arr2[j++]);
    }
    return final;
}
/// ->> Leetcode 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s=0, e=m-1;
        while(e>0 && s<n){
            if(nums1[e] > nums2[s] )
                swap(nums1[e--],nums2[s++]);
            else break;
        }
        s=0;
        for(int i=m; i<m+n; i++){
            nums1[i] = nums2[s++];
        }
        sort(nums1.begin(),nums1.end());
        return;
    }
};

// ============================================================================================== ///

/// Ques 4 --- Return dupliacte from an array of n+1 size
/// ->> Codestudio
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// o(n)
    sort(arr.begin(),arr.end());

    int ans = -1;
    if(arr[n-1] == arr[n-2]) return arr[n-1];

    for(int i=0; i<n-2; i++){
        if(arr[i] == arr[i+1]) ans = arr[i];
    }

    return ans;
}
/// ->> Leetcode 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size()-1, ans =-1;
        if(nums[n-1] == nums[n]) return nums[n];
        for(int i=0; i<n; i++){
            if(nums[i] == nums[i+1]) ans = nums[i];
        }
        return ans;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Missing and repeating numbers
/// ->> Codestudio
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> ans;
	vector<int> fq(n+1,0);
	for(int i=0; i<n; i++){
		fq[arr[i]] += 1;
	}
	// for(int i=0; i<n+1; i++){
	// 	cout << " " << fq[i] << " ";
	// }
	for(int i=1; i<fq.size(); i++){
		if(fq[i] == 0) ans.first = i;
		if(fq[i] == 2) ans.second = i;
	}
	
	return ans;
}
/// ->> Leetcode 
-

// ============================================================================================== ///

/// Ques 6 --- Count inversions
/// ->> Codestudio
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long  inversions = 0;

    for(int i=0; i<n; i++){
        int left = arr[i];
        for(int j=i; j<n; j++){
            if(left > arr[j]) inversions++;
        }
    }
    return inversions;
}
/// ->> Leetcode 
-

// ============================================================================================== ///