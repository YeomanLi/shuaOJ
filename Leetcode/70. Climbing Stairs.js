/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  if (2 >= n) return n
  let pre = 1, cur = 2
  let res
  for (let i = 3; i <= n; ++i) {
    res = pre + cur
    pre = cur
    cur = res
  }
  return res
};