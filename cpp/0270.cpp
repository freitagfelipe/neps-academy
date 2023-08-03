#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> pic;

pic neutral {-1, '\0'};

void draw(multiset<pic> &player, queue<pic> &cards, int n) {
    assert((int) cards.size() >= n);

    while (n--) {
        player.insert(cards.front());

        cards.pop();
    }
}

void next_player(int &at, int direction, int p) {
    if (direction == 1) {
        at = (at + 1) % p;
    } else {
        at = --at < 0 ? p - 1 : at;
    }
}

pic comp(const pic &a, const pic &b){
    if(a.first > b.first) {
        return a;
    }

    if (b.first > a.first) {
        return b;
    }

    if(a.second > b.second) {
        return a;
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, m, n;

    while (cin >> p >> m >> n && p != 0) {
        vector<multiset<pic>> players_hand(p, multiset<pic>());

        for (int i {}; i < p; ++i) {
            for (int j {}; j < m; ++j) {
                pic cc;

                cin >> cc.first >> cc.second;

                players_hand[i].insert(cc);
            }
        }

        queue<pic> cards;

        for (int i {p * m}; i < n; ++i) {
            pic cc;

            cin >> cc.first >> cc.second;

            cards.push(cc);
        }

        int direction {cards.front().first == 12 ? -1 : 1}, at {};
        bool can_calculate_penality {true};
        pic last_card {cards.front()};

        cards.pop();

        while (true) {
            if (can_calculate_penality) {
                can_calculate_penality = false;

                int val {last_card.first};
                bool skip {};

                if (val == 7) {
                    skip = true;

                    draw(players_hand[at], cards, 2);
                } else if (val == 1) {
                    skip = true;

                    draw(players_hand[at], cards, 1);
                } else if (val == 11) {
                    skip = true;
                }

                if (skip) {
                    next_player(at, direction, p);

                    continue;
                }
            }

            pic player_card {neutral};

            for (const pic &card : players_hand[at]) {
                if (card.first == last_card.first || card.second == last_card.second) {
                    player_card = comp(player_card, card);
                }
            }

            if (player_card == neutral) {
                player_card = cards.front();

                cards.pop();

                players_hand[at].insert(player_card);
            }

            if (player_card.first == last_card.first || player_card.second == last_card.second) {
                players_hand[at].erase(players_hand[at].find(player_card));

                last_card = player_card;

                if (players_hand[at].empty()) {
                    cout << at + 1 << '\n';

                    break;
                }

                can_calculate_penality = true;
            }

            if (can_calculate_penality && player_card.first == 12) {
                direction *= -1;
            }

            next_player(at, direction, p);
        }
    }

    return 0;
}