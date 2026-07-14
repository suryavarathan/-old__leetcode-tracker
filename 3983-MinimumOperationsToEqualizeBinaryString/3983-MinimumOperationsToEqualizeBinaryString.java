// Last updated: 7/14/2026, 3:19:42 PM
class Solution {
    public int minOperations(String s, int k) {
        int n = s.length(), m = 0;
        int[] dist = new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        List<TreeSet<Integer>> list = new ArrayList<>();
        list.add(new TreeSet<>());
        list.add(new TreeSet<>());
        for(int i=0;i<=n;i++){
            list.get(i%2).add(i);
            if(i<n && s.charAt(i) == '0'){
                m++;
            }
        }
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(m);
        dist[m] = 0;
        list.get(m%2).remove(m);
        while(!queue.isEmpty()){
            m = queue.poll();
            int c1 = Math.max(k-n+m,0), c2 = Math.min(m,k);
            int lnode = m+k-2*c2, rnode = m+k-2*c1;
            TreeSet<Integer> node = list.get(lnode%2);
            for(Integer m2=node.ceiling(lnode);m2!=null && m2<=rnode;m2=node.ceiling(lnode)){
                dist[m2] = dist[m] + 1;
                queue.offer(m2);
                node.remove(m2);
            }
        }
        return dist[0] == Integer.MAX_VALUE ? -1 : dist[0];
    }
}