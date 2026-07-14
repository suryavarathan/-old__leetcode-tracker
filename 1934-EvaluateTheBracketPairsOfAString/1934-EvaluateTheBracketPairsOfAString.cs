// Last updated: 7/14/2026, 3:26:37 PM
public class Solution {
    public string Evaluate(string s, IList<IList<string>> knowledge) {
        // Step 1: Build fast lookup map key → value
        Dictionary<string, string> map = new();
        foreach (var pair in knowledge) {
            string key = pair[0];
            string val = pair[1];
            map[key] = val;
        }

        // Step 2: Build result with StringBuilder
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int n = s.Length;

        while (i < n) {
            if (s[i] == '(') {
                // Start collecting key
                int start = i + 1;
                while (i < n && s[i] != ')') i++;
                if (i == n) break; // malformed, but constraints guarantee valid

                string key = s.Substring(start, i - start);

                // Append value or "?"
                if (map.TryGetValue(key, out string value)) sb.Append(value);
                else  sb.Append("?");
                i++; // skip ')'
            } 
            else{
                sb.Append(s[i]);
                i++;
            }
        }

        return sb.ToString();
    }
}