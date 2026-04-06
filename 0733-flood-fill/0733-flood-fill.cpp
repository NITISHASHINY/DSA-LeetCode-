class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc]; //each location access
        //edge case
        if(old_color == color) return image;
        dfs(image, sr, sc, old_color, color);
        return image; // we r not taking a new array we r jus changing the array

    }
void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor){
    //chack boundARIES
    if(r<0 || r>= image.size() || c<0 || c>= image[0].size()) return;
    if (image[r][c] != originalColor) return;
        // Change the color
        image[r][c] = newColor;
        // Recursive calls for neighbors
        dfs(image, r + 1, c, originalColor, newColor);
        dfs(image, r - 1, c, originalColor, newColor);
        dfs(image, r, c + 1, originalColor, newColor);
        dfs(image, r, c - 1, originalColor, newColor);
}

};