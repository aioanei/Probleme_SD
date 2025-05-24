#include <fstream>
#include <queue>
#include <vector>
#include <functional>
#include <utility> 
using namespace std;

int main() {
    ifstream f("proc2.in");
    ofstream g ("proc2.out");

    int N, M;
    f >> N >> M;

    priority_queue<int, vector<int>, greater<int>> free_processors;
    for (int i = 1; i <= N; ++i)
        free_processors.push(i);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy_processors;

    for (int i = 0; i < M; ++i) {
        long long S, D;
        f >> S >> D;

        while (!busy_processors.empty() && busy_processors.top().first <= S) {
            free_processors.push(busy_processors.top().second);
            busy_processors.pop();
        }

        int proc = free_processors.top();
        free_processors.pop();

        g << proc << "\n";
        busy_processors.emplace(S + D, proc);
    }

    return 0;
}