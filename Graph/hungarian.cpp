const int64_t INF64 = int64_t(2e18) + 5;

vector<int> assignment;

template<typename T>
int64_t hungarian(vector<vector<T>> costs) {
    int n = int(costs.size());
    int m = costs.empty() ? 0 : int(costs[0].size());

    if (n > m) {
        vector<vector<T>> new_costs(m, vector<T>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                new_costs[j][i] = costs[i][j];

        swap(costs, new_costs);
        swap(n, m);
    }

    vector<int64_t> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);

    for (int i = 1; i <= n; i++) {
        vector<int64_t> min_v(m + 1, INF64);
        vector<bool> used(m + 1, false);
        p[0] = i;
        int j0 = 0;

        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            int64_t delta = INF64;

            for (int j = 1; j <= m; j++)
                if (!used[j]) {
                    int64_t cur = costs[i0 - 1][j - 1] - u[i0] - v[j];

                    if (cur < min_v[j]) {
                        min_v[j] = cur;
                        way[j] = j0;
                    }

                    if (min_v[j] < delta) {
                        delta = min_v[j];
                        j1 = j;
                    }
                }

            for (int j = 0; j <= m; j++)
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    min_v[j] -= delta;
                }

            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    // Note that p[j] is the row assignment of column j (both 1-based). If p[j] = 0, the column is unassigned.
    assignment = p;
    return -v[0];
}

