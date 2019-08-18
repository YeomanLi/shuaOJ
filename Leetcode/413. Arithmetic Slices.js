/**
 * @param {number[]} A
 * @return {number}
 */
var numberOfArithmeticSlices = function(A) {
  let res = 0
  let dp = new Array(A.length).fill(0)
  for (let i = 2; i < A.length; ++i) {
    if (A[i] - A[i - 1] === A[i - 1] - A[i - 2])
      dp[i] = dp[i - 1] + 1
    res += dp[i]
  }
  return res
};
