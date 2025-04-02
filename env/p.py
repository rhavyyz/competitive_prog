def test_case():
    n = int(input())
    op = [[] for _ in range(n+1)]
    val = [[] for _ in range(n+1)]
    for i in range(1, n + 1):
        tmp = input().split()
        op[i] = [tmp[0], tmp[2]]
        val[i] = [int(tmp[1]), int(tmp[3])]
 
    op[0] = ['+', '+']
    val[0] = [1, 1]
 
    dp = [[0, 0] for _ in range(n + 2)]
    dp[n + 1][0] = dp[n + 1][1] = 1
 
    for i in range(n, 0, -1):
        dp[i][0] = (dp[i + 1][0] + (val[i][0] - 1) * max(dp[i + 1][0], dp[i + 1][1])) if op[i][0] == 'x' else dp[i + 1][0]
        dp[i][1] = (dp[i + 1][1] + (val[i][1] - 1) * max(dp[i + 1][0], dp[i + 1][1])) if op[i][1] == 'x' else dp[i + 1][1]
 
    print([p[0] for p in dp])
    print([p[1] for p in dp])
    print("")


    ans = 0
    for i in range(1, n + 1):
        sm = 0
        if op[i][0] == '+':
            sm += val[i][0]
        if op[i][1] == '+':
            sm += val[i][1]
        ans += sm * max(dp[i + 1][0], dp[i + 1][1])
 
    ans += dp[1][0]
    ans += dp[1][1]
 
    # print(ans)
 
t = int(input())
for _ in range(t):
    test_case()
    
# model solution, dp
