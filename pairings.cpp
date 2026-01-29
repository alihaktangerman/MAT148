#include <iostream>
#include <vector>
using namespace std;

vector<bool> used(6,false);
vector<pair<int,int>> tables;
int counter = 0;

void solve() {
    int p1 = 0;
    while (used[p1++] && p1!=6);
    if (p1 != 6) {
        for (auto p2 = p1+1; p2 != 6; p2++) {
            if (!used[p2]) {
                used[p1] = true;
                used[p2] = true;
                tables.push_back(pair<int,int>{p1,p2});
                solve();
                used[p1] = false;
                used[p2] = false;
                tables.pop_back();
            }
        }
    } else {
        for (auto a: tables) {
            cout << "(" << a.first << " " << a.second << ")" << " ";
        }
        cout << endl;
        counter++;
    }
}

int main() {
    solve();
    cout << counter << endl;
}
