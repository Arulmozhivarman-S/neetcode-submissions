class Solution {
    public int[] plusOne(int[] d) {
        
        int carry = 1;

        int n = d.length;

        for(int i=n-1; i>=0; i--){
            d[i] = d[i] + carry;
            if(carry>0) carry--;
            if(d[i]==10){
                d[i] = 0;
                carry++;
            }
        }
        if(carry>0){
            int[] arr = new int[n+1];
            arr[0] = 1;
            for(int i=0; i<n; i++){
                arr[i+1] = d[i];
            }
            return arr;
        }
        return d;
    }
}
