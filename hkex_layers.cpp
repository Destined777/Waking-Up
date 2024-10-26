/*
建图，bfs即可， 主要难点在于接收输入（未知行，每行未知个int）
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int start;
  cin >> start;
  cin.ignore();
  unordered_map<int, set<int>> rec;
  string line;
  while (true) {
    getline(cin, line);
    if (line.empty()) {
      break;
    }
    stringstream ss(line);
    int first;
    ss >> first;
    if (rec.find(first) == rec.end()) {
      rec[first] = set<int>();
    }
    int num;
    while (ss >> num) {
      rec[first].insert(num);
      if (rec.find(num) == rec.end()) {
        rec[num] = set<int>();
      }
      rec[num].insert(first);
    }
  }
  unordered_map<int, bool> visit;
  visit[start] = true;
  queue<int> now;
  now.push(start);
  while (!empty(now)) {
    int n = now.size();
    vector<int> nowSeq = vector<int>();
    for (int i = 0; i < n; i++) {
      int nowNum = now.front();
      nowSeq.push_back(nowNum);
      set<int> next = rec[nowNum];
      for (const int& element: next) {
        if (visit[element] != true) {
          now.push(element);
          visit[element] = true;
        }
      }
      now.pop();
    }
    sort(nowSeq.begin(), nowSeq.end());
    for (int i = 0; i < nowSeq.size(); i++) {
      if (i == n-1) {
        cout << nowSeq[i] << endl;
      } else {
        cout << nowSeq[i] << " ";
      }
    }
  }
  return 0;
}
