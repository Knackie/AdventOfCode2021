#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// Define a cuboid and its sign for overlap calculation
struct Cuboid {
    long long x1, x2, y1, y2, z1, z2;
    int sign; // 1 for adding, -1 for subtracting
};

// Function to compute overlap between two cuboids
bool getOverlap(const Cuboid& a, const Cuboid& b, Cuboid& overlap) {
    overlap.x1 = max(a.x1, b.x1);
    overlap.x2 = min(a.x2, b.x2);
    overlap.y1 = max(a.y1, b.y1);
    overlap.y2 = min(a.y2, b.y2);
    overlap.z1 = max(a.z1, b.z1);
    overlap.z2 = min(a.z2, b.z2);

    if (overlap.x1 <= overlap.x2 && overlap.y1 <= overlap.y2 && overlap.z1 <= overlap.z2) {
        return true;
    }
    return false;
}

// Function to compute the total volume of the cuboids
long long computeVolume(vector<pair<Cuboid, int>>& cuboids) {
    long long totalVolume = 0;

    for (auto& cub : cuboids) {
        long long xLength = cub.first.x2 - cub.first.x1 + 1;
        long long yLength = cub.first.y2 - cub.first.y1 + 1;
        long long zLength = cub.first.z2 - cub.first.z1 + 1;

        totalVolume += cub.second * xLength * yLength * zLength;
    }
    return totalVolume;
}

int main() {
    vector<pair<Cuboid, int>> cuboids;
    string state;
    long long x1, x2, y1, y2, z1, z2;

    // Input parsing
    while (cin >> state) {
        char temp;
        cin >> temp >> temp; // Skip "x="
        cin >> x1 >> temp >> temp >> x2 >> temp; // Read x range
        cin >> temp >> temp; // Skip "y="
        cin >> y1 >> temp >> temp >> y2 >> temp; // Read y range
        cin >> temp >> temp; // Skip "z="
        cin >> z1 >> temp >> temp >> z2; // Read z range

        Cuboid newCuboid = {x1, x2, y1, y2, z1, z2, state == "on" ? 1 : -1};
        vector<pair<Cuboid, int>> updatedCuboids;

        // Check for overlaps
        for (auto& [existingCuboid, sign] : cuboids) {
            Cuboid overlap;
            if (getOverlap(existingCuboid, newCuboid, overlap)) {
                updatedCuboids.push_back({overlap, -sign}); // Subtract overlapping regions
            }
        }

        // Add the new cuboid if it is "on"
        if (newCuboid.sign == 1) {
            updatedCuboids.push_back({newCuboid, 1});
        }

        // Merge the new cuboids into the list
        cuboids.insert(cuboids.end(), updatedCuboids.begin(), updatedCuboids.end());
    }

    // Compute and print the total volume
    cout << "Total On Cubes: " << computeVolume(cuboids) << endl;

    return 0;
}
