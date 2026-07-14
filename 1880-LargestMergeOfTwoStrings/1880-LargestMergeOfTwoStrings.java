// Last updated: 7/14/2026, 3:27:51 PM
class Solution {
    public String largestMerge(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int j = 0;

        while (i < word1.length() && j < word2.length()) {
            if (word1.substring(i).compareTo(word2.substring(j)) > 0) {
                sb.append(word1.charAt(i));
                i++;
            } else {
                sb.append(word2.charAt(j));
                j++;
            }
        }

        if (i < word1.length()) {
            sb.append(word1.substring(i));
        }

        if (j < word2.length()) {
            sb.append(word2.substring(j));
        }

        return sb.toString();
    }
}