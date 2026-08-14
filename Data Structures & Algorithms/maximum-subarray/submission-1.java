class Solution {
    public int maxSubArray(int[] nums) {
        int mx = Integer.MIN_VALUE, cur = 0;

        for(int i:nums){
            cur = Math.max(cur+i, i);
            mx = Math.max(mx, cur);
        }
        return mx;
    }
}
