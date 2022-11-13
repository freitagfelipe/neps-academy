#include <iostream>
#include <map>

using namespace std;

void add(map<int, int> &m, int num) {
    ++m[num];
}

int main() {
    map<int, int> esquerdo, direito;
    int n, answer {0};

    cin >> n;

    for (int i {0}; i < n; ++i) {
        int num;
        char pe;

        cin >> num >> pe;

        if (pe == 'D') {
            add(direito, num);
        } else {
            add(esquerdo, num);
        }
    }

    for (auto [fd, sd] : direito) {
        map<int, int>::iterator it {esquerdo.find(fd)};

        if (it != esquerdo.end()) {
            answer += sd < it->second ? sd : it->second;
        }
    }

    cout << answer << endl;

    return 0;
}