#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

vector<string> split(string a) {
    string curr = "";
    vector<string> ans;
    for (const char& i : a) {
        if (i == ' ') {
           ans.push_back(curr);
           curr = "";
        }
        else {
            curr += i;
        }
    }
    if (curr != "") {
        ans.push_back(curr);
    }
    return ans;
}
pair<int, char> find_value(string card) {
    char a = card[0];
    if (a == 'A') {
        return make_pair(1, card[1]);
    }
    else if (50 <= a && a <= 57) {
        return make_pair(a - '0', card[1]);
    }
    else if (a == 'T') {
        return make_pair(10, card[1]);
    }
    else if (a == 'J') {
        return make_pair(11, card[1]);
    }
    else if (a == 'Q') {
        return make_pair(12, card[1]);
    }
    else {
        return make_pair(20, card[1]);
    }
}
void playCards(string hand, string piles) {
    vector<pair<int, char>> hand_cards;
    for (const string& i : split(hand)) {
        hand_cards.push_back(find_value(i));
    } 
    vector<string> split_piles = split(piles);
    pair<int, char> pile_cards[8];
    for (int i = 0; i < 4; i++) {
        pile_cards[2 * i] = find_value(split_piles[i]);
        pile_cards[2 * i + 1] = make_pair(-1, 'E');
    }
    for (const auto& i : hand_cards) {
        cout << i.first << i.second << ' ';
    }
    cout << '\n';
    for (const auto& i : pile_cards) {
        cout << i.first << i.second << ' ';
    }
}
int main(void) {
    playCards("JC 5C 7D QD KC 8S KS", "6C 7S 6H 9H");

    // string a = "JC 5C 7D QD KC 8S KS";
    // vector<string> ans = split(a);
    // for (const string& card : ans) {
    //     cout << card << endl;
    // }
    return 0;
}