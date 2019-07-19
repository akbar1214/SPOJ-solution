#include<bits/stdc++.h>

using namespace std;

const int con = static_cast<int>(1e8 + 5);

double area(double a, double b, double c, double d) {

    double s = (a + b + c + d) / 2.0;
    return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}

int main() {

    int T;
    cin >> T;
    while (T--) {

        double a, b, c, d;
        cin >> a >> b >> c >> d;
        printf("%0.2f\n", area(a, b, c, d));
    }
}
