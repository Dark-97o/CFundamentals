#include <stdio.h>
#include <limits.h>

#define N 4
#define INF INT_MAX

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[16][N];

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) return dist[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) ans = newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    printf("Minimum travelling cost: %d\n", tsp(1, 0));
    return 0;
}