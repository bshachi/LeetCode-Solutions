class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 1, e = n - 2, m;

        while (true) {
            m = (e + s) / 2;
            if (arr[m] > arr[m - 1] && arr[m] < arr[m + 1]) s = m + 1;
            else if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1]) e = m - 1;
            else return m;
        }
    }
};