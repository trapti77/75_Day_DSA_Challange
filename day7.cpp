int search(vector<int>& nums, int tr) {
        int n=nums.size();
        if(nums[0]<nums[n-1]&&tr<=nums[0]&&tr>=nums[n-1]){
          int s=0;
          int h=n-1;
          while(s<=h){
            int m=(s+h)/2;
            if(nums[m]==tr)return m;
            if(tr>nums[m]){
             s=m+1;
            }
            else
            {
                h=m-1;
            }
          }
        }
       
        int s=0;
        int h=n-1;
       while(s<=h){
        int m=(s+h)/2;
        if(nums[m]==tr)return m;
        if(nums[m]<nums[h]){
        if(tr>=nums[m]&&tr<=nums[h]){
            s=m+1;
        }
        else
        {
            h=m-1;
        }
        }
        else
        {
         if(tr>=nums[s]&&tr<=nums[m]){
            h=m-1;
         }
         else
         {
            s=m+1;
         }
        }
       }
        return -1;
    }