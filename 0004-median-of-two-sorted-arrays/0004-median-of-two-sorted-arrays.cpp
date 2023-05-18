class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;

        int n = nums1.size(), m = nums2.size();
        int current = 0, k = (n+m)/2;
        bool prev = 0, odd = ((n+m)%2 == 0) ? false : true;
        if (!odd) k--; 


        if (!n)
        {
            if (odd) return nums2[k];
            return (float(nums2[k] + nums2[k+1]))/2;
        }
        if (!m)
        {
            if (odd) return nums1[k];
            return (float(nums1[k] + nums1[k+1]))/2;
        }

        auto s1 = nums1.begin(), s2 = nums2.begin();
        auto e1 = nums1.end(), e2 = nums2.end();

        while (k-current>5 || current>k)
        {
            auto mid = max(s1 ,s1 + distance(s1, e1)/2 - 1);
            auto temp = min(lower_bound(s2, e2, *mid), e2-1);
            if (temp == e2-1) mid = min(lower_bound(s1, e1, *temp), e1-1);
            current = (distance(nums2.begin(), temp) + distance(nums1.begin(), mid)); 

            
            if (k-current<=5 && k>=current) 
            {
                s1 = mid;
                s2 = temp;
                break;
            }

            else if (current < k)
            {
                s1 = min(mid+1, e1-1);
                s2 = min(temp+1, e2-1);
            }

            else
            {
                e1 = mid;
                e2 = temp;
            }
            
            current = (distance(nums2.begin(), s2) + distance(nums1.begin(), s1)); 
        }

        while(s1 > nums1.begin() && s2 < nums2.end() && *(s1-1) > *(s2))
        {
            s1--;
            s2++;
        }

        while(s2 > nums2.begin() && s1 < nums1.end() && *(s1) < *(s2-1))
        {
            s1++;
            s2--;
        }

        k -= current;

        
        int arr[10];
        for (int i = 0; i<10; i++)
        {
            if (s1 >= nums1.end() && s2 >= nums2.end()) break;
            if (s1 >= nums1.end()) 
            {
                arr[i] = *s2;
                s2++;
                continue;
            }
            if (s2 >= nums2.end()) 
            {
                arr[i] = *s1;
                s1++;
                continue;
            }


            if (*s1 <= *s2)
            {
                arr[i] = *s1;
                s1++;
            }
            else
            {
                arr[i] = *s2;
                s2++;
            }
        }


        if (odd) ans = arr[k]; 
        else ans = float((arr[k] + arr[k+1]))/2;

        return ans;

    }
};