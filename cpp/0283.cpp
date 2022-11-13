#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    int t;

    cin >> t;

    for (int i {}; i < t; ++i) {
        int m, n;

        cin >> m >> n;

        unordered_map<string, string> mp;

        for (int i {}; i < m; ++i) {
            string k, v;

            cin >> k;

            cin.get();

            getline(cin, v);

            mp[k] = v;
        }
        
        for (int i {}; i < n; ++i) {
            string aux;

            getline(cin, aux);

            stringstream ss(aux);

            int count {};

            while (ss >> aux) {
                if (count++ > 0) {
                    cout << " ";
                }

                if (mp.find(aux) != mp.end()) {
                    cout << mp[aux];
                } else {
                    cout << aux;
                }
            }

            cout << '\n';
        }
    }

    return 0;
}