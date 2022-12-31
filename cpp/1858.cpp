#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap {
public:
    BinaryHeap(bool is_min_heap = false) : v(1) {
        this->is_min_heap = is_min_heap;
    }

    void push(int val) {
        this->v.push_back(val);

        this->fix_push(this->v.size() - 1);
    }

    void pop() {
        if (this->v.size() == 1) {
            throw std::runtime_error("Binary heap size == 0");
        }

        swap(this->v[1], this->v.back());

        this->v.pop_back();

        fix_pop(1);
    }

    int top() {
        if (this->v.size() == 1) {
            throw std::runtime_error("Binary heap size == 0");
        }

        return this->v[1];
    }

    int second_top() {
        if (this->v.size() == 1) {
            throw std::runtime_error("Binary heap size == 0");
        }

        if (this->v.size() == 3) {
            return this->v[2];
        }
        
        return max(this->v[2], this->v[3]);
    }
private:
    vector<int> v;
    bool is_min_heap;

    int get_parent(int node) {
        return node / 2;
    }

    int get_left(int node) {
        return node * 2;
    }

    int get_right(int node) {
        return node * 2 + 1;
    }

    void fix_push(int node) {
        if (node == 1) {
            return;
        }

        if ((!this->is_min_heap && v[this->get_parent(node)] > v[node]) || (this->is_min_heap && v[this->get_parent(node)] < v[node])) {
            return;
        }

        swap(v[this->get_parent(node)], v[node]);

        this->fix_push(this->get_parent(node));
    }

    void fix_pop(int node) {
        if (this->get_left(node) >= v.size()) {
            return;
        }

        int child_node {this->get_left(node)};

        if (this->get_right(node) < v.size() 
            && (!this->is_min_heap && v[this->get_left(node)] <= v[this->get_right(node)]
            || this->is_min_heap && v[this->get_left(node)] >= v[this->get_right(node)])
        ) {
            child_node = this->get_right(node);
        }

        if ((!this->is_min_heap && v[node] >= v[child_node]) || (this->is_min_heap && v[node] <= v[child_node])) {
            return;
        }

        swap(v[node], v[child_node]);

        fix_pop(child_node);
    }
};

int main() {
    int n;
    BinaryHeap bh;

    cin >> n;

    for (int i {}; i < n; ++i) {
        int op;

        cin >> op;

        if (op == 1) {
            bh.pop();
        } else if (op == 2) {
            int aux;

            cin >> aux;

            bh.push(aux);
        } else if (op == 3) {
            cout << bh.top() << '\n';
        } else {
            cout << bh.second_top() << '\n';
        }
    }

    return 0;
}