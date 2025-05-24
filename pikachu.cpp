#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

ifstream f ("pikachu.in");
ofstream g ("pikachu.out");

multiset<int> s_left;
multiset<int> s_right;
long long sum_left = 0;
long long sum_right = 0;
int K_global;

void balance_sets() {
    if (K_global == 0) return;
    int target_s_left_size = (K_global + 1) / 2;

    while (s_left.size() < target_s_left_size) {
        if (s_right.empty()) break; 
        long long val = *s_right.begin();
        s_right.erase(s_right.begin());
        sum_right -= val;
        s_left.insert(val);
        sum_left += val;
    }

    while (s_left.size() > target_s_left_size) {
        if (s_left.empty()) break; 
        long long val = *s_left.rbegin();
        s_left.erase(prev(s_left.end()));
        sum_left -= val;
        s_right.insert(val);
        sum_right += val;
    }
}

void add_val(long long x) {
    if (s_left.empty() || x <= *s_left.rbegin()) {
        s_left.insert(x);
        sum_left += x;
    } else { 
        s_right.insert(x);
        sum_right += x;
    }
    balance_sets();
}

void remove_val(long long x) {
    auto it_left = s_left.find(x);
    if (it_left != s_left.end()) {
        s_left.erase(it_left);
        sum_left -= x;
    } else { 
        auto it_right = s_right.find(x);
        if (it_right != s_right.end()) { 
            s_right.erase(it_right);
            sum_right -= x;
        }
    }
    balance_sets();
}

long long calculate_current_cost() {
    if (K_global == 0) return 0; 
    if (s_left.empty()) return LLONG_MAX;
    long long median_val = *s_left.rbegin();
    
    long long current_cost = 0;
    current_cost += (sum_right - (long long)s_right.size() * median_val);
    current_cost += ((long long)s_left.size() * median_val - sum_left);
    
    return current_cost;
}

int main() {
    int N;
    f >> N >> K_global;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        f >> h[i];
    }

    if (K_global == 0 || K_global > N) {
        if (K_global == 0) {
            g << 0 << endl;
            return 0;
        }
        if (K_global > N && N > 0) { 
        }
    }
    
    if (N == 0) {
        g << 0 << endl;
        return 0;
    }

    for (int i = 0; i < K_global; ++i) {
        add_val(h[i]);
    }

    long long min_total_cost = calculate_current_cost();

    for (int i = 1; i <= N - K_global; ++i) {
        remove_val(h[i - 1]);
        add_val(h[i + K_global - 1]);
        min_total_cost = min(min_total_cost, calculate_current_cost());
    }

    g << min_total_cost << endl;

    return 0;
}

