#include <iostream>
#include <list>

using namespace std;

list<string>::iterator find(list<string> &l, string &s) {
    list<string>::iterator it {l.begin()};

    for (; it != l.end(); ++it) {
        if (*it == s) {
            break;
        }
    }

    return it;
}

void print(list<string> &l) {
    string s;

    cin >> s;

    list<string>::iterator it {find(l, s)};

    cout << (++it != l.end() ? *it : "0") << endl;
}

void update(list<string> &l) {
    string a, b;

    cin >> a >> b;

    l.remove(a);

    list<string>::iterator it {find(l, b)};

    l.insert(++it, a);
}

int main() {
    int n, m;

    cin >> n >> m;

    list<string> l;

    for (int i {}; i < n; ++i) {
        string s;

        cin >> s;

        l.push_back(s);
    }

    for (int i {}; i < m; ++i) {
        int op;

        cin >> op;
        
        if (op == 1) {
            update(l);
        } else {
            print(l);
        }
    }

    int count {};

    for (string &s : l) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << s;
    }

    cout << '\n';

    return 0;
}
