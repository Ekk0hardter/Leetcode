MOD = 10**9 + 7
n, k = map(int, input().split())
s = input()
x_count = s.count('X')
dp = [[0] * k for _ in range(n + 1)]
dp[0][0]=1
for i in range(1, n + 1):
    if s[i - 1] == 'W':
        dp[i][0]=sum(dp[i - 1]) % MOD
    elif s[i - 1] == 'B':
        dp[i][1]=dp[i - 1][0]
        for j in range(2, k):
            dp[i][j]=dp[i - 1][j - 1]
    else:
        dp[i][0]=sum(dp[i - 1]) % MOD
        dp[i][1]=(dp[i - 1][0]+dp[i - 1][1]) % MOD
        for j in range(2, k):
            dp[i][j]=dp[i - 1][j - 1]
ans = pow(2, x_count, MOD)-sum(dp[n]) % MOD
print((ans + MOD) % MOD)