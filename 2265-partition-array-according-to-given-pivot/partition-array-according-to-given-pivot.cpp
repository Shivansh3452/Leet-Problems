class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> large;
        int j=0,freq=0;
        for(auto& it: nums){
            if(it<pivot)
                small.push_back(it);
            else if(it>pivot&&it!=pivot)
                large.push_back(it);
            else{
                freq++;
            }
        }
        for(int i=0;i<small.size();i++){
            nums[j]=small[i];
            j++;
        }
        while(freq!=0){
            freq--;
            nums[j]=pivot;
            j++;
        }
        for(int i=0;i<large.size();i++){
            nums[j]=large[i];
            j++;
        }
        return nums;
    }
};