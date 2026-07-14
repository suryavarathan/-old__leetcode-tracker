// Last updated: 7/14/2026, 3:22:49 PM
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        int min = 0;
        int max = (1<<n)-1;
        Set<Integer> s = new HashSet<>();
        for(String num : nums)s.add(Integer.parseInt(num, 2));
        String out = "";
        for(int i=max;i>=min;--i){
            if(!s.contains(i)) {
                out = Integer.toBinaryString(i);
                break;
            }
        }
        while(out.length()<n)out="0"+out;
        return out;
    }
}
