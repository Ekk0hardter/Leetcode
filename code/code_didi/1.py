n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
dp = [[0] * n for _ in range(n)]
dp[0][0]=a[0][0]
# 初始化第一行
for j in range(1, n):
    dp[0][j]=dp[0][j - 1]+a[0][j]
# 初始化第一列
for i in range(1, n):
    dp[i][1]=dp[i - 1][1]+a[i][1]
# 填充dp数组
for i in range(1, n):
    for j in range(1, n):
        dp[i][j]=max(dp[i - 1][j], dp[i][j - 1]+a[i][j])
ans = 0
# 考虑第n行和第n列的情况
for j in range(n):
    ans = max(ans, dp[n - 1][j])
for i in range(n):
    ans = max(ans, dp[i][n - 1])
print(ans)