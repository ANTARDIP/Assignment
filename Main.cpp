#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

vector<int> maximizeNetworkQuality(vector<vector<int>>& towers, int radius) {
    int maxQuality = numeric_limits<int>::min();
    vector<int> result = {-1, -1};

    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int networkQuality = 0;

            for (const auto& tower : towers) {
                int xi = tower[0], yi = tower[1], qi = tower[2];
                double d = sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));

                if (d <= radius) {
                    int signalQuality = static_cast<int>(floor(qi / (1 + d)));
                    networkQuality += signalQuality;
                }
            }

            if (networkQuality > maxQuality) {
                maxQuality = networkQuality;
                result = {x, y};
            } else if (networkQuality == maxQuality) {
                if (x < result[0] || (x == result[0] && y < result[1])) {
                    result = {x, y};
                }
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
    int radius = 2;

    vector<int> result = maximizeNetworkQuality(towers, radius);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}