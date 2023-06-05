/// Ques 1 --- Set Matrix 0
/// ->> Codestudio
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix) {
//   cout << "Row " << matrix.size() << " Colums " << matrix[0].size();

  // Extra arrays for tracking
  int r = matrix.size(), c = matrix[0].size();
  int row[r] = {0};
  int col[c] = {0};

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (matrix[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        if(row[i] == 1 || col[j] == 1){
            matrix[i][j] = 0;
        }
    }
  }
}

/// ->> Leetcode 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> row(r);
        vector<int> col(c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// ============================================================================================== ///

/// Ques 2 --- Pascals Triangle
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output(numRows);
        for(int i=0; i<numRows; i++){
            output[i].resize(i+1, 1);
            for(int j=1; j<i; j++){
                output[i][j] = output[i-1][j-1] + output[i-1][j];
            }
        }
        return output;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Next Permutation
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return nums;

        }
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        return nums;
    }
};

// ============================================================================================== ///

/// Ques 4 --- Kadane's Algorithm
/// ->> Codestudio
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxi = LONG_MIN;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if( sum < 0){
            sum = 0;
        }
    }
    if(maxi < 0) return 0;
    return maxi;
}
/// ->> Leetcode 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if( sum < 0){
                sum = 0;
            }
        }
        // if(maxi < 0) return 0;
        return maxi;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Sort an array of 0's, 1's and 2's
/// ->> Codestudio
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int low=0,mid=0,high=n-1;
    
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low++],arr[mid++]);
        }else if(arr[mid] == 1){
            mid++;
        }else {
            swap(arr[high--],arr[mid]);
        }
    }
}

/// ->> Leetcode 
class Solution {
public:
    void fillColor(int color,int val, vector<int>& nums){
        while(color != 0){
            nums.push_back(val);
            color--;
        }
    }
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                red++;
            }else if(nums[i] == 1){
                white++;
            }else{
                blue++;
            }
        }
        nums.clear();
        fillColor(red,0,nums);
        fillColor(white,1,nums);
        fillColor(blue,2,nums);
    }
};

// ============================================================================================== ///

/// Ques 6 --- Stocks Buy and Sell
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};

// ============================================================================================== ///