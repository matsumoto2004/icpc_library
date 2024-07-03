#include <bits/stdc++.h>
using namespace std;
 
int main() {
  set<int> S;
 
  S.insert(3);
  S.insert(7);
  S.insert(8);
  S.insert(10);
  // 既に3は含まれているのでこの操作は無視される
  S.insert(3);
 
  // 集合の要素数を出力
  cout << "size: " << S.size() << endl;
 
  // 7が含まれるか判定
  if (S.count(7)) {
    cout << "found 7" << endl;
  }
  // 5が含まれるか判定
  if (S.count(5)) {
    cout << "found 5" << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  stack<int> s;
  s.push(10);
  s.push(1);
  s.push(3);
 
  cout << s.top() << endl;  // 3 (最後に追加した値)
  s.pop();
  cout << s.top() << endl;  // 1 (その前に追加した値)
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  deque<int> d;
  d.push_back(10);
  d.push_back(1);
  d.push_back(3);
 
  // この時点で d の内容は { 10, 1, 3 } となっている
 
  cout << d.front() << endl; // 10 (先頭の要素)
  d.pop_front();  // 先頭を削除
 
  // この時点で d の内容は { 1, 3 } となっている
 
  cout << d.back() << endl;  // 3 (末尾の要素)
  d.pop_back();  // 末尾を削除
 
  // この時点で d の内容は { 1 } となっている
 
  d.push_front(5);
  d.push_back(2);
 
  // この時点で d の内容は { 5, 1, 2 } となっている
 
  cout << d.at(1) << endl; // 1
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> a = {0, 10, 13, 14, 20};
  // aにおいて、12 以上最小の要素は 13
  cout << *lower_bound(a.begin(), a.end(), 12) << endl; // 13
 
  // 14 以上最小の要素は 14
  cout << *lower_bound(a.begin(), a.end(), 14) << endl; // 14
 
  // 10 を超える最小の要素は 13
  cout << *upper_bound(a.begin(), a.end(), 10) << endl; // 13
}