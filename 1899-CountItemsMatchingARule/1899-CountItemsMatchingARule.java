// Last updated: 7/14/2026, 3:27:23 PM
class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int matches = 0;
        int ruleKeyIndex = getRuleKeyIndex(ruleKey);

        for (List<String> item : items) {
            if (item.get(ruleKeyIndex).equals(ruleValue)) {
                matches++;
            }
        }

        return matches;
    }

    private int getRuleKeyIndex(String key) {
        switch (key) {
            case "type": return 0;
            case "color": return 1;
            case "name": return 2;
        }
        throw new IllegalArgumentException("Invalid key");
    }
}