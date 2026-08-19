class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        double ans=0;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if(j==nums2.size()){
            while(i<nums1.size()){
                nums.push_back(nums1[i]);
                i++;
            }
        }
        if(i==nums1.size()){
            while(j<nums2.size()){
                nums.push_back(nums2[j]);
                j++;
            }
        }
        int n=nums.size();
        if(n%2==1){
            ans=(double)nums[n/2];
            return ans;
        }
        ans=(double)(
            nums[n/2-1]+nums[n/2])/2;
        return ans;
    }
};