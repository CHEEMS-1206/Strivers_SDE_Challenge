/// Ques 1 --- Majority Element (n/2 times)
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int ele=arr[0];
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(count==0)ele=arr[i];
            count+=(ele==arr[i])?1:-1;
        }
        return ele;
    }
};

// ============================================================================================== ///

/// Ques 2 --- Pow(x, n)
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double num = 1;
        if(n>=0){
            while(n>0){
                num *= x;
                n--;
            }
        }
        else{
            n = -n;
            while(n>0){
                num *= x;
                n--;
            }
            num = 1.0/num;
        }
        return num;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Search a 2D Matrix
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};

// ============================================================================================== ///

/// Ques 4 --- Majority Element (n/3 times)
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto it : m){
            if(it.second > n/3){
                v.push_back(it.first);
            } 
        }
        return v;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Unique Paths
/// ->> Codestudio
-
/// ->> Leetcode 
class Solution {
public:
    int rec(int m, int n,int a, int b, vector<vector<int>> &v)
    {
        if(v[m][n]!=-1)return v[m][n];
        if(m==a || n==b)return 1;
        v[m][n] = rec(m+1,n,a,b, v)+rec(m, n+1,a,b,v);
        return v[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        return rec(0,0,m-1,n-1, v);
    }
};

// ============================================================================================== ///

/// Ques 6 --- Reverse pairs
/// ->> Codestudio
-

/// ->> Leetcode 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long reversePairsCount = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > 2*(long long)nums[j]){
                    reversePairsCount++;
                }
            }
        }
        return reversePairsCount;
    }
};

// ============================================================================================== ///