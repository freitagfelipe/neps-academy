#include <iostream>
#include <list>

using namespace std;

void add(list<pair<int, string>> &l, bool front = true) {
    int id;
    string name;

    cin >> id >> name;

    if (front) {
        l.push_front({id, name});
    } else {
        l.push_back({id, name});
    }
}

void remove(list<pair<int, string>> &l, bool front = true) {
    if (l.size() == 0) {
        cout << "0 0\n";

        return;
    }

    pair<int, string> p;

    if (front) {
        p = l.front();        

        l.pop_front();
    } else {
        p = l.back();

        l.pop_back();
    }

    cout << p.first << " " << p.second << '\n';
}

int main() {
    int n;

    cin >> n;

    list<pair<int, string>> l;

    for (int i {}; i < n; ++i) {
        int op;

        cin >> op;

        if (op == 1 || op == 2) {
            add(l, op == 1);
        } else if (op == 3 || op == 4) {
            remove(l, op == 3);
        }
    }

    return 0;
}
