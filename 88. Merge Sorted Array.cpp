class Solution {
public:
    // 插入排序(将val插入到有序序列nums1中)
    void insertSort(vector<int>& nums1, int& m, int val) {
        int i = m - 1;
        
        while (i > -1 && nums1[i] > val) {
            nums1[i + 1] = nums1[i];
            i--;
            
        }
        
        nums1[i + 1] = val;
        m++;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // n趟插排
        for (int i = 0; i < n; i++) {
            insertSort(nums1, m, nums2[i]);
        }
    }
};
