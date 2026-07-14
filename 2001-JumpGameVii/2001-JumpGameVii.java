// Last updated: 7/14/2026, 3:25:11 PM
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        boolean[] vis = new boolean[n];

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);

        int last_vis = 0;

        while (!queue.isEmpty()) {

            int index = queue.poll();

            if (index == n - 1) {
                return true;
            }

            int low = index + minJump;
            if(low >= n ){
                continue;
            }

            low = Math.max(low,last_vis);

            int high = index + maxJump;
            high = (high < n) ? high : n-1;

            last_vis = high;

            for (int j = low; j <= high; j++) {
                if (s.charAt(j) == '0' && !vis[j]) {
                    queue.offer(j);
                    vis[j] = true;
                }
            }

        }

        return false;

    }
}
