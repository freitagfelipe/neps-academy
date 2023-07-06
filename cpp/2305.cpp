#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull fast_exponentiation(ull b, ull e) {
    if (e == 0) {
        return 1; 
    }

    ull answer {fast_exponentiation(b, e / 2)};

    answer = (answer * answer);

    if (e % 2 == 0) {
        return answer;
    }

    return answer * b;
}

int get_id(char ch) {
	return ch - 'a' + 1;
}

vector<int> p_pow;
const int p {31};
const int m {(int) 1e9 + 9};

void precompute_pow(int n) {
    p_pow.push_back(1);

    for (int i {1}; i < n; ++i) {
        p_pow.push_back((p_pow.back() * p) % m);
    }
}

ull compute_hash(const string &s) {
	ull hash_value {};
	ull p_pow_idx {};

	for (char ch : s) {
		hash_value = (hash_value + get_id(ch) * p_pow[p_pow_idx++]) % m;
	}

	return hash_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    unordered_map<ull, int> ump;

    precompute_pow(11);

    for (int i {}; i < n; ++i) {
        string aux;
        
        cin >> aux;

        ump[compute_hash(aux)] = i;
    }

    string s;

    cin >> s;

    vector<int> matches;

    ull hash_value {};
    int p_pow_idx {};

    for (char ch : s) {
        hash_value = (hash_value + get_id(ch) * p_pow[p_pow_idx++]) % m;

        if (ump.count(hash_value) == 1) {
            matches.push_back(ump[hash_value]);

            p_pow_idx = 0;
            hash_value = 0;
        }
    }

    ull ans {};
    int pow {(int) matches.size() - 1};

    for (int match : matches) {
        ans += (match * fast_exponentiation(n, pow--));
    }

    cout << ans << '\n';

    return 0;
}