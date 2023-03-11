string AddString(string& a, string& b) {
    int n = a.size();
    int m = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string sum;
    for (int i = 0, j = 0, c = 0; i < n || j < m || c > 0; ) {
        if (i < n) {
            c += a[i] - '0';;
            i++;
        }

        if (j < m) {
            c += b[j] - '0';
            j++;
        }

        sum.push_back((c % 10) + '0');
        c /= 10;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(sum.begin(), sum.end());

    return sum;
}

bool PassLeadingZeroCheck(string_view s) {
    return !s.empty() && (s.size() == 1 || s[0] != '0');
}

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; i + j <= n; j++) {
                string a = num.substr(0, i);
                string b = num.substr(i, j);
                if (!PassLeadingZeroCheck(a) || !PassLeadingZeroCheck(b)) continue;

                int right = i + j;
                while (true) {
                    string sum = AddString(a, b);
                    int sum_len = sum.size();
                    if (right + sum_len > n) break;
                    if (sum != num.substr(right, sum_len)) break;

                    a = b; b = sum;
                    right += sum_len;
                    if (right == n) return true;
                }
            }
        }

        return false;
    }
};