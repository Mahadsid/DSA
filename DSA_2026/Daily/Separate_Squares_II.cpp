/*
3454. Separate Squares II
Solved
Hard
Hint
You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted only once in this version.

 

Example 1:

Input: squares = [[0,0,1],[2,2,1]]

Output: 1.00000

Explanation:



Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.

Example 2:

Input: squares = [[0,0,2],[1,1,1]]

Output: 1.00000

Explanation:



Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.

 

Constraints:

1 <= squares.length <= 5 * 104
squares[i] = [xi, yi, li]
squares[i].length == 3
0 <= xi, yi <= 109
1 <= li <= 109
The total area of all the squares will not exceed 1015.
*/
/*Approach
Convert each square into two y-events:

start event at y
end event at y + l
Compress x-coordinates

Sweep from bottom to top

Maintain active x-intervals using a segment tree

Calculate area strip by strip

Store all strips

Find where cumulative area reaches half

Interpolate to get the exact y-value
*/
class Solution {
    vector<int> cnt;
    vector<double> segLen;
    vector<double> xs;

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[idx] += val;
        } else {
            int m = (l + r) >> 1;
            update(idx<<1, l, m, ql, qr, val);
            update(idx<<1|1, m, r, ql, qr, val);
        }

        if (cnt[idx] > 0) {
            segLen[idx] = xs[r] - xs[l];
        } else if (r - l == 1) {
            segLen[idx] = 0.0;
        } else {
            segLen[idx] = segLen[idx<<1] + segLen[idx<<1|1];
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        for (auto &s : squares) {
            xs.push_back((double)s[0]);
            xs.push_back((double)s[0] + (double)s[2]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        struct Event {
            double y, x1, x2;
            int type;
        };

        vector<Event> events;
        for (auto &s : squares) {
            double x = (double)s[0];
            double y = (double)s[1];
            double l = (double)s[2];
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end(),
             [](auto &a, auto &b) { return a.y < b.y; });

        int n = xs.size();
        cnt.assign(4 * n, 0);
        segLen.assign(4 * n, 0.0);

        vector<array<double,3>> strips;
        double total = 0.0;
        double prevY = events[0].y;

        for (auto &e : events) {
            if (e.y > prevY) {
                double w = segLen[1];
                double h = e.y - prevY;
                total += w * h;
                strips.push_back({prevY, h, w});
                prevY = e.y;
            }
            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();
            update(1, 0, n - 1, l, r, e.type);
        }

        double half = total / 2.0;
        double acc = 0.0;

        for (auto &s : strips) {
            double area = s[1] * s[2];
            if (acc + area >= half) {
                return s[0] + (half - acc) / s[2];
            }
            acc += area;
        }
        return 0.0;
    }
};
