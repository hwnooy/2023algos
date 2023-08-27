#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int getParent(int n) {
    if (n == parent[n]) return n;  // 자기 부모가 자기면 자기 반환
    return parent[n] = getParent(parent[n]);
}

bool find(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) return true;
    else return false;
}

void unionParent(int a, int b) {
    int a_parent = getParent(a);
    int b_parent = getParent(b);

    if (a_parent != b_parent) {
        parent[a] = b;
    }
}


int main() {

    int n, m; // n : 컴퓨터(노드) 개수, m : 간선 개수
    int a, b, cost, result;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> kru(m);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        kru[i] = { cost, {a,b} };
    }
    sort(kru.begin(), kru.end());

    for (int i = 0; i < m; i++) {
        cost = kru[i].first;
        a = kru[i].second.first;
        b = kru[i].second.second;

        if (!find(a, b)) {
            result += cost;
            unionParent(a, b);
        }
    }
    cout << result;

}

