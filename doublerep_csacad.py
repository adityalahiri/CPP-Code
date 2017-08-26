#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    string s, a, b; cin >> s >> a >> b;
    int l = (int)a.size();
    for (int i = 0; i + l <= (int)s.size(); i += 1) {
        if (s.substr(i, l) == a) {
            s = s.substr(0, i) + b + s.substr(i + l, s.size());
            i += l - 1;
        } else if (s.substr(i, l) == b) {
            s = s.substr(0, i) + a + s.substr(i + l, s.size());
            i += l - 1;
        }
    }
    cout << s << '\n';
    return 0;
}
