/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  let pre1 = 0, pre2 = 0
  for (let i = 0; i < nums.length; ++i) {
    let cur = Math.max(pre2 + nums[i], pre1)
    pre2 = pre1
    pre1 = cur
  }
  return pre1
};
console.log(rob([1, 2, 3, 1]))
console.log(rob([2, 7, 9, 3, 1]))
