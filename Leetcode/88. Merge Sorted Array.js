/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let p1 = m - 1, p2 = n - 1
  let p3 = m + n - 1
  while (0 <= p3) {
    if (0 > p2 || nums1[p1] > nums2[p2])
      nums1[p3--] = nums1[p1--]
    else if (0 > p1 || nums1[p1] <= nums2[p2])
      nums1[p3--] = nums2[p2--]
  }
  return nums1
};
console.log(merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3))
