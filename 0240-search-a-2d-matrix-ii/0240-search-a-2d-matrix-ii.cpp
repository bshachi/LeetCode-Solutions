class Solution {
public:
    int sea (vector<vector<int>>& mat, int target, int col, int t, int b) {
        int s = t, e = b, mid;
        while (s < e) {
            mid = (s+e)/2;
            if (mat[mid][col] < target) s = mid+1;
            else if (mat[mid][col] > target) e = mid;
            else return -1;
        }
        return mat[s][col] > target? s : s+1;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        
        int t = 0, b = n-1, l = 0, r = m-1;

        while (l <= r && t <= b) {
            // cout<<"b "<<b<<" t "<<t<<" r "<<r<<" l "<<l<<endl;
            // cout<<mat[t][l]<<" "<<mat[b][r]<<endl;
            if (target < mat[t][l] || target > mat[b][r]) return false;

            b = sea(mat, target, l, t, b) - 1;
            if (b < 0) return true;
            // cout<<mat[t][l]<<" "<<mat[b][r]<<endl;
            if (target > mat[b][r]) return false;

            r = upper_bound(mat[t].begin()+l, mat[t].begin()+r+1, target) - mat[t].begin() - 1;
            // cout<<mat[t][l]<<" "<<mat[b][r]<<endl;
            if (mat[t][r] == target) return true;
            if (target > mat[b][r]) return false;

            t = sea(mat, target, r, t, b) - 1;
            if (t < 0) return true;
            // cout<<mat[t][l]<<" "<<mat[b][r]<<endl;
            if (target < mat[t][l]) return false;

            l = lower_bound(mat[b].begin()+l, mat[b].begin()+r+1, target) - mat[b].begin();
            // cout<<mat[t][l]<<" "<<mat[b][r]<<endl;
            if (mat[b][l] == target) return true;
            if (target < mat[t][l]) return false;
        }
        return false;
    }
};