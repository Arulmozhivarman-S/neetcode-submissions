class Solution {
    public boolean isHappy(int n) {
        
        Set<Integer> s = new HashSet<>();

        while(n>1){

            int sum = 0;

            while(n>0){
                int d = n%10;
                sum+= (d*d);
                n/=10;
            }
            n = sum;
            if( s.contains(sum) ) return false;
            if(sum==1) return true;
            s.add(sum);
        }
        return n==1;
    }
}
