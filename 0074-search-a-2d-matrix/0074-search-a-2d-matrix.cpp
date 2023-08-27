class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        if (mat[0][0] > target || mat[n-1][m-1] < target) return false;

        int l = 0, r = n - 1, mid, row;
        while (l <= r) {
            mid = (l+r)/2;
            if (mat[mid][0] > target) r = mid-1;
            else if (mat[mid][m-1] < target) l = mid+1;
            else {
                row = mid;
                break;
            }
        }

        l = 0, r = m-1;
        while (l <= r) {
            mid = (l+r)/2;
            if (mat[row][mid] > target) r = mid-1;
            else if (mat[row][mid] < target) l = mid+1;
            else return true;
        }
        return false;
    }
};