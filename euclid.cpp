#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("euclid.in");
ofstream g ("euclid.out");
int n, m, test, i, ma[402][402],h,w, colt_ss, res, sol;
int cmmdc(int a, int b) {
    int r;
    while (b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}


int main(){
    f >>test;
    for (int cnt = 1; cnt <= test; cnt++) {

        sol = 0;
        f >>m>>n>>h>>w;
        for (int i = 1; i<=m; i++) {
            for (int j = 1; j<=n; j++) {
                f >>ma[i][j];
            }
        }

        for (int i = 1; i <= m-h+2; i++) {
            for (int j = 1; j<= n-w+2; j++) {
                colt_ss = ma[i][j];
                res = colt_ss;

                for (int i1 = i; i1 < i+h; i1++) {
                    for (int j1 = j; j1 < j+w; j1++) {
                        res = cmmdc(res, ma[i1][j1]);
                        if (res <= sol)
                            break;
                    }
                    if (res <= sol)
                        break;
                }

                sol = max(sol, res);


            }
        }


        g << "Case #"<<cnt<<": "<<sol << "\n";
    }


    return 0;
}