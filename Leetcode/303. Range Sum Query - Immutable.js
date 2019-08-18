/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
  this.sums = new Array(nums.length)
  this.sums[0] = nums[0]
  for (let i = 1; i < nums.length; ++i) {
    this.sums[i] = nums[i] + this.sums[i - 1]
  }
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
  return i ? this.sums[j] - this.sums[i - 1] : this.sums[j]
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(i,j)
 */
