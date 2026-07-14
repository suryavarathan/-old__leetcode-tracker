// Last updated: 7/14/2026, 3:25:01 PM
class Solution {
public:
    string maxValue(string n, int x) {
        string s;

        if (n[0] == '-') {
            s += '-';
            bool found = false;

            for (int i = 1; i < n.size(); i++) {
                if (!found && n[i] - '0' > x) {
                    s += to_string(x);
                    found = true;
                }
                s += n[i];
            }

            if (!found)
                s += to_string(x);
        } else {
            bool found = false;

            for (int i = 0; i < n.size(); i++) {
                if (!found && n[i] - '0' < x) {
                    s += to_string(x);
                    found = true;
                }
                s += n[i];
            }

            if (!found)
                s += to_string(x);
        }

        return s;
    }
};