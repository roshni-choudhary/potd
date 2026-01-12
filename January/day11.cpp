#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // DP arrays to track state for each column
        vector<int> height(cols, 0);  // Height of consecutive 1's
        vector<int> left(cols, 0);    // Left boundary (inclusive)
        vector<int> right(cols, cols); // Right boundary (exclusive)
        
        int maxArea = 0;
        
        // Process each row
        for (int i = 0; i < rows; i++) {
            // Update heights
            for (int j = 0; j < cols; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            
            // Update left boundaries (scan left to right)
            int curLeft = 0;  // Leftmost valid position
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            
            // Update right boundaries (scan right to left)
            int curRight = cols;  // Rightmost valid position
            for (int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = cols;
                    curRight = j;
                }
            }
            
            // Calculate max area for current row
            for (int j = 0; j < cols; j++) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }
        }
        
        return maxArea;
    }
};