#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    using uint = uint32_t;

    uint n, w;
    cin >> n >> w;

    vector<vector<pair<uint, uint>>> columns(w);

    for (uint i = 0; i < n; i++) {
        uint x, y;
        cin >> x >> y;
        columns[x - 1].emplace_back(y, i);
    }

    uint last_block = 0;
    for (auto& column : columns) {
        ranges::sort(column);
        ranges::reverse(column);
        last_block = max(last_block, column.empty() ? numeric_limits<uint>::max() : column.back().first);
    }

    uint q;
    cin >> q;

    vector<tuple<uint, uint, uint>> queries(q);
    for (uint i = 0; i < q; i++) {
        auto& [t, a, idx] = queries[i];
        cin >> t >> a;
        idx = i;
    }

    ranges::sort(queries);
    vector<bool> gone(n);

    auto fall_through = [&](uint time) {
        last_block = 0;
        for (auto& column : columns) {
            auto [current_block, block_idx] = column.back();
            column.pop_back();

            gone[block_idx] = true;
            if (!column.empty()) {
                uint fall_distance = min(column.back().first - 1, time);
                column.back().first -= fall_distance;
            }

            last_block = max(last_block, column.empty() ? numeric_limits<uint>::max() : column.back().first);
        }
      
        if (last_block != numeric_limits<uint>::max()) {
            last_block += time;
        }
    };

    vector<bool> answer(q);
    for (const auto& [t, a, idx] : queries) {
        while (t >= last_block) {
            fall_through(last_block);
        }

        answer[idx] = gone[a - 1];
    }

    for (const auto v : answer) {
        cout << (v? "No" : "Yes") << '\n';
    }

    return 0;
}


//https://atcoder.jp/contests/abc391/submissions/67243712