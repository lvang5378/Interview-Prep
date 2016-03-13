/*
/the same as rob (all the houses in a line)
/instead we need to go thourgh the nums twice  (two pass)
/compare rob(0, nums.size()-2) and rob(1, nums.size()-1)   
/return the larger one
*/

class Solution {
public:
    int rob(vector<int>& nums) {
       
       
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> maxs (nums.size(), 0);
        maxs[0] = nums[0];
        maxs[1] = max(nums[0], nums[1]);
        for(int i =2;i<nums.size();i++){
            maxs[i] = max(maxs[i-2]+nums[i], maxs[i-1]);   ''' //******main part of house robber I  *******//'''
        }
        int  tempMax = maxs[nums.size()-2];
        
        maxs[1] = nums[1];
        maxs[2] = max(nums[1], nums[2]);
        for(int i =3;i<nums.size();i++){
            maxs[i] = max(maxs[i-2]+nums[i], maxs[i-1]);
        }
        return max(tempMax, maxs[nums.size()-1]);
    }
    
};
