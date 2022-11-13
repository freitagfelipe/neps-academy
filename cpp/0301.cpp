#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n, m;

    cin >> n >> m;

    for (int i {}; i < n; ++i) {
        int aux;

        cin >> aux;
		
		mp[aux] = i;
    }

    vector<int> lis; 

    for (int i {}; i < m; ++i) {
        int aux;

        cin >> aux;

        if (mp.find(aux) == mp.end()) {
            continue;
        }

        vector<int>::iterator it {lower_bound(lis.begin(), lis.end(), mp[aux])};

        if (it == lis.end()) {
            lis.push_back(mp[aux]);
        } else {
            *it = mp[aux];
        }
    }

    cout << lis.size() << '\n';

    return 0;
}