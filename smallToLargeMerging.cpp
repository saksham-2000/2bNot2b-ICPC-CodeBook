#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5;

// nodes will be 1-indexed like in the problem
vector<int> adj[MAX_N + 1];

set<int> colors[MAX_N + 1];
int distinct_num[MAX_N + 1];

void process_colors(int curr, int parent)
{
    for (int n : adj[curr])
    {
        if (n != parent)
        {
            process_colors(n, curr);
            // make x the larger set always
            if (colors[curr].size() < colors[n].size())
            {
                swap(colors[curr], colors[n]);
            }
            for (int item : colors[n])
            {
                colors[curr].insert(item);
            }
        }
    }
    distinct_num[curr] = colors[curr].size();
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        colors[i].insert(a);
    }
    for (int i = 1; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    process_colors(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << distinct_num[i] << (i < n ? " " : "\n");
    }
}