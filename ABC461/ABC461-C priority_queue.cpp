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
  
  // 各色の先頭をtop、残りをjewelsへ集約
  priority_queue<int> topValues;
  priority_queue<int> jewels;
  rep(c, 1, n + 1){
    if(!gemsByColor[c].empty()){
      topValues.push(gemsByColor[c].top());
      gemsByColor[c].pop();
    }

    while(!gemsByColor[c].empty()){
      jewels.push(gemsByColor[c].top());
      gemsByColor[c].pop();
    }
  }

  rep(i, 0, m){
    totalValue += topValues.top();
    topValues.pop();
  }

  while(!topValues.empty()){
    jewels.push(topValues.top());
    topValues.pop();
  }

  // 残りの K - M 個を選ぶ
  rep(i, 0, k - m){
    totalValue += jewels.top();
    jewels.pop();
  }

  cout << totalValue;
  return 0;
}