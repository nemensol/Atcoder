#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long totalValue = 0;
    int n, k, m;
    cin >> n >> k >> m;

    // 色ごとに宝石価値を保持
    vector<vector<int>> gemsByColor(n + 1);
    rep(i, 0, n){
        int c, v;
        cin >> c >> v;
        gemsByColor[c].push_back(v);
    }

    // 色ごとに価値の高い順へソート
    rep(c, 1, n + 1){
        sort(gemsByColor[c].begin(), gemsByColor[c].end(), greater<int>());
    }

    // 各色の先頭をtop、それ以外をtailへ集約
    vector<int> top;
    top.reserve(n);

    vector<int> tail;
    tail.reserve(n);

    rep(c, 1, n + 1){
        if(!gemsByColor[c].empty()){
            top.push_back(gemsByColor[c][0]);
            rep(i, 1, static_cast<int>(gemsByColor[c].size())){
                tail.push_back(gemsByColor[c][i]);
            }
        }
    }

    sort(top.begin(), top.end(), greater<int>());
    rep(i, m, static_cast<int>(top.size())){
        tail.push_back(top[i]);
    }

    sort(tail.begin(), tail.end(), greater<int>());

    rep(i, 0, m){
        totalValue += top[i];
    }

    rep(i, 0, k - m){
        totalValue += tail[i];
    }

    cout << totalValue;
    return 0;
}