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

    // 各色の先頭(最大価値)を候補化してM色選ぶ
    vector<pair<int, int>> colorBest;
    rep(c, 1, n + 1){
        if(!gemsByColor[c].empty()){
            colorBest.push_back({gemsByColor[c][0], c});
        }
    }
    sort(colorBest.begin(), colorBest.end(), greater<pair<int, int>>());

    vector<char> usedColor(n + 1, 0);
    rep(i, 0, m){
        totalValue += colorBest[i].first;
        usedColor[colorBest[i].second] = 1;
    }

    // 先頭で使った分以外を集める
    vector<int> jewels;
    jewels.reserve(n - m);
    rep(c, 1, n + 1){
        rep(i, 0, static_cast<int>(gemsByColor[c].size())){
            if(usedColor[c] && i == 0) continue;
            jewels.push_back(gemsByColor[c][i]);
        }
    }

    sort(jewels.begin(), jewels.end(), greater<int>());

    rep(i, 0, k - m){
        totalValue += jewels[i];
    }

    cout << totalValue;
    return 0;
}