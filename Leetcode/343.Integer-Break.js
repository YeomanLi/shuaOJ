var integerBreak = function(n) {
  let dp = []
  dp[0] = 0
  dp[1] = 1
  dp[2] = 1
  for (let i = 3; i <= n; ++i)  dp[i] = 0
  for (let i = 3; i <= n; ++i) {
    for (let j = 1; j <= i; ++j) {
      dp[i] = Math.max(dp[i], (i - j) * j)
      dp[i] = Math.max(dp[i], dp[i - j] * j)
    }
  }
  return dp[n]
};
console.log(integerBreak(10))