#include <iostream>
#include <vector>
#include <queue>

int main(){
  long long total_value = 0;
  int n, k, m;
  std::cin >> n >> k >> m;

  // 色ごとに宝石の価値を保持する
  std::vector<std::priority_queue<int>> jewel_value_4Ci(n + 1);
  for(int i=0;i<n;i++){
    int c, v;
    std::cin >> c >> v;
    jewel_value_4Ci[c].push(v);
  }
  
  // 各色の最大価値を候補として集め、M色ぶん選ぶ
  std::priority_queue<std::pair<int, int>> color_best;
  for(int c = 1; c <= n; c++){
    if(!jewel_value_4Ci[c].empty()){
      color_best.push({jewel_value_4Ci[c].top(), c});
    }
  }
  
  for(int i = 0; i < m; i++){
    auto [value, color] = color_best.top();
    color_best.pop();
    total_value += value;
    jewel_value_4Ci[color].pop();
  }
  
  // 残りの宝石をすべて集める
  std::priority_queue<int> jewels;
  for(int c = 1; c <= n; c++){
    while(!jewel_value_4Ci[c].empty()){
      jewels.push(jewel_value_4Ci[c].top());
      jewel_value_4Ci[c].pop();
    }
  }

  // 残りの K - M 個を選ぶ
  for(int i = 0; i < k - m; i++){
    total_value += jewels.top();
    jewels.pop();
  }

  std::cout << total_value;
  return 0;
}