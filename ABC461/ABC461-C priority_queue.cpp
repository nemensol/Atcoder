#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long totalValue = 0;
  int n, k, m;
  cin >> n >> k >> m;

  // 色ごとに宝石の価値を保持する
  vector<priority_queue<int>> gemsByColor(n + 1);
  rep(i, 0, n){
    int c, v;
    cin >> c >> v;
    gemsByColor[c].push(v);
  }
  
  // 各色の最大価値を候補として集め、M色ぶん選ぶ
  priority_queue<pair<int, int>> colorBest;
  rep(c, 1, n + 1){
    if(!gemsByColor[c].empty()){
      colorBest.push({gemsByColor[c].top(), c});
    }
  }
  
  rep(i, 0, m){
    auto [value, color] = colorBest.top();
    colorBest.pop();
    totalValue += value;
    gemsByColor[color].pop();
  }
  
  // 残りの宝石をすべて集める
  priority_queue<int> jewels;
  rep(c, 1, n + 1){
    while(!gemsByColor[c].empty()){
      jewels.push(gemsByColor[c].top());
      gemsByColor[c].pop();
    }
  }

  // 残りの K - M 個を選ぶ
  rep(i, 0, k - m){
    totalValue += jewels.top();
    jewels.pop();
  }

  cout << totalValue;
  return 0;
}