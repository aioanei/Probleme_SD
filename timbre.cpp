#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

ifstream f("timbre.in");
ofstream g("timbre.out");

priority_queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<>> costuri;

int n, m, k;

int main() {
    f >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int c, x;
        f >> x >> c;
        q.push({x, c});
    }

    int rez = 0;
    while (n > 0) {
        while (!q.empty() && q.top().first >= n) {
            costuri.push(q.top().second);
            q.pop();
        }
        rez += costuri.top();
        costuri.pop();
        n -= k;
    }

    g << rez;
    return 0;
}