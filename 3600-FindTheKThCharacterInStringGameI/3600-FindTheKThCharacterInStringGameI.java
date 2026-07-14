// Last updated: 7/14/2026, 3:20:46 PM
class Solution {
    public char kthCharacter(int k) {
        String word = "ab";
        while (word.length() < k) {
            StringBuilder newWord = new StringBuilder();
            for (char c : word.toCharArray()) {
                newWord.append((char)((c - 'a' + 1) % 26 + 'a'));
            }
            word += newWord.toString();
        }
        return word.charAt(k - 1);
    }
}