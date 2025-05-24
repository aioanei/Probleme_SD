#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("stramosi.in");
ofstream g ("stramosi.out");
int n, m, i, j, q, p, cnt;
int stramos[250002][19];
int main() {
    f >> n >> m;
    for (i = 1; i <= n; i++) {
        f >> stramos[i][0];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 18; j++) {
            stramos[i][j] = stramos[stramos[i][j-1]][j-1];
        }
    }

    for (i = 1; i <= m; i++) {
        f >> q >> p;
        cnt = 0;
        while (p) {
            if ( p & 1) {
                q = stramos[q][cnt];
            }
                p >>= 1;
                cnt ++;

        }
        g << q << '\n';
    }
    return 0;
}