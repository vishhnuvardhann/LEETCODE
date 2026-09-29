// 215 ms | 140.1 MB
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L')
                    id[i][j] = cnt++;
            }
        }

        if (cnt == 0)
            return 0;

        int full = (1 << cnt) - 1;

        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        queue<array<int, 4>> q;
        q.push({sx, sy, energy, 0});
        best[sx][sy][0] = energy;

        int steps = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == full)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X' || e == 0)
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (classroom[nx][ny] == 'L')
                        nm |= 1 << id[nx][ny];

                    if (classroom[nx][ny] == 'R')
                        ne = energy;

                    if (nm == full)
                        return steps + 1;

                    if (ne <= best[nx][ny][nm])
                        continue;

                    best[nx][ny][nm] = ne;
                    q.push({nx, ny, ne, nm});
                }
            }

            steps++;
        }

        return -1;
    }
};