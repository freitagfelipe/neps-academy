#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, d;

    while (cin >> n >> d && n != 0) {
        string number;

        cin >> number;

        string answer;

        int erased {};

        for (char ch : number) {
            while (answer.size() > 0 && ch > answer.back() && erased != d) {
                answer.pop_back();
                ++erased;
            }

            if (answer.size() < n - d) {
                answer.push_back(ch);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}