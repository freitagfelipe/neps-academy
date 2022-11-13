#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int size;

    cin >> size;

    vector<int> fila(size);

    for (int i {}; i < size; ++i) {
        cin >> fila[i];
    }

    cin >> size;

    set<int> removidos;

    for (int i {}; i < size; ++i) {
        int num;

        cin >> num;

        removidos.insert(num);
    }

    for (int indentifier : fila) {
        if (removidos.find(indentifier) == removidos.end()) {
            cout << indentifier << " ";
        }
    }

    cout << '\n';

    return 0;
}