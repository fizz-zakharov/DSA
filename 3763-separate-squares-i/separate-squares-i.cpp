class Solution {
private:
    double ar(double k, vector<vector<int>>& v, double half) {
        double area = 0.0;
        for (auto &it : v) {
            double y = it[1];
            double l = it[2];

            if (y >= k) continue;

            double height = min(l, k - y);
            area += height * l;

            if (area >= half) return area;
        }
        return area;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double total = 0.0;
        double low = 1e18, high = -1e18;

        for (auto &it : squares) {
            double y = it[1];
            double l = it[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double half = total / 2.0;

        for (int i = 0; i < 50; i++) {
            double mid = (low + high) / 2.0;
            if (ar(mid, squares, half) >= half)
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
