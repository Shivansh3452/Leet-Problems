class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        if(total%3!=0)
            return false;
        int p1=-1;
        int target=(int)total/3;
        int sum=0;
        for(int i=0;i<n-2;i++){
            sum+=arr[i];
            if(sum==target){
                p1=i;       //0 indexing   
                break;  
            }
        }
        if(p1==-1)
            return false;
        int sum2=0;
        int p2=-1;
        for(int i=p1+1;i<n-1;i++){
            sum2+=arr[i];
            if(sum2==target){
                p2=i;
                break;
            }
        }
        return p2!=-1;
    }
};