// Last updated: 7/14/2026, 3:24:36 PM
public class Solution {
    public int MaximumRemovals(string s, string p, int[] removable){
        int left = 0,right = removable.Length;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if possible to remove first mid indices
            if (IsPossible(s, p, removable, mid))  {
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }

        return ans;
    }

private bool IsPossible(string s, string p, int[] removable, int k){
        // Mark first k removable indices as removed
        bool[] removed = new bool[s.Length];
        for (int i = 0; i < k; i++)  removed[removable[i]] = true;
        
        // Two pointers to check if p is still subsequence
        int j = 0; // pointer in p
        for (int i = 0; i < s.Length; i++) {
            if (removed[i]) continue; // skip removed
            if (j < p.Length && s[i] == p[j])  j++;
        }

        return j == p.Length; // all characters of p matched
    }
}