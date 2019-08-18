/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  if (null == nums || 0 == nums.length) return 0
  if (1 === nums.length)  return nums[0]
  return Math.max(helper(nums.slice(0, nums.length - 1)), helper(nums.slice(1, nums.length)))
};

function helper (nums) {
  let pre1 = 0, pre2 = 0
  for (let i = 0; i < nums.length; ++i) {
    let cur = Math.max(pre1, pre2 + nums[i])
    pre2 = pre1
    pre1 = cur
  }
  return pre1
}
