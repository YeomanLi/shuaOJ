/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  let dp = new Array(n).fill(1)
  // 一行一行更新，省空间
  for (let i = 1; i < m; ++i) {
    for (let j = 1; j < n; ++j) {
      dp[j] += dp[j - 1]
    }
  }
  return dp[n - 1]
};
