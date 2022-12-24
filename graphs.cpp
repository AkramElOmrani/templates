
const int nax = 51;
int n;
vector<vector<bool>> grid(nax, vector<bool>(nax));
vector<pair<int, int>> dir = {
	{0, -1}, {0, 1}, {-1, 0}, {1, 0}
};
vector<pair<int, int>> dir2 = {
	{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};

bool inside(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && !vis[x][y];
}
auto inside = [&](int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && grid[x][y];
};