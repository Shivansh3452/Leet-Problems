class Solution {
public:
    vector<vector<int>> result;

    bool sumchecker(vector<int>& temp,int n){
        int sum=0;
        for(int j=0;j<temp.size();j++){
            sum+=temp[j];
        }
        if(sum==n)
            return true;
        return false;
    }
    bool checker(vector<int>& temp,int k){
        
        if(temp.size()!=k)
            return false;
        unordered_map<int,int> mpp;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>9)
                return false;
            mpp[temp[i]]++;
        }
        for(auto& it:mpp){
            if(it.second>1)
                return false;
        }
        return true;
    }
    void solver(int i,int k, int n,vector<int>&temp){
        if(i>9){
            if(checker(temp,k) && sumchecker(temp,n)){
                result.push_back(temp);
            }
            return;
        }
        temp.push_back(i);
        solver(i+1,k,n,temp);
        temp.pop_back();
        solver(i+1,k,n,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solver(1,k,n,temp);
        return result;
    }
};