class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maji = nums[0];
        int c_maj = 1;
        for(int i =1;i<nums.size();i++){
            if(nums[i] == maji){
                c_maj++;
            }
            else
                c_maj--;
            
            if(c_maj==0){
                c_maj =1;
                maji = nums[i];
            }
        }
        return maji;
    }
};