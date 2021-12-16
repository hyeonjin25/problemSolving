#include <iostream>
#include <math.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, x, n, m;
    cin >> T;

    for (int t = 0; t < T; T++) {
        cin >> x >> n >> m;

        long long sum = 0;
       /* for (int i = 1; i < n + 1; i++) {
            sum += pow(x, i);
        }*/
        sum = x * (pow(x, n) - 1) / (x - 1);
        cout << sum % m << "\n";
    }

}