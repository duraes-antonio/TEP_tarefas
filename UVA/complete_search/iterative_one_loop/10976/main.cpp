#include <iostream>
#include <map>

using namespace std;

int main() {

    int k, yk;
    map<int, int> map_x_y;

    while (cin >> k && k > 0) {

        for(int i = k+1; i <= k+k; i++) {
            yk = i * k;

            if (yk % (i-k) == 0) map_x_y[i] = yk / (i-k);
        }

        if (!map_x_y.empty()) cout << map_x_y.size() << endl;

        for(auto &x_y: map_x_y) {
            printf("1/%d = 1/%d + 1/%d\n", k, x_y.second, x_y.first);
        }

        map_x_y.clear();
    }

    return 0;
}