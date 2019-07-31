/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let i = 0, j = numbers.length - 1
  while (i < j) {
    const temp = numbers[i] + numbers[j]
    if (temp > target)  --j
    else if (temp < target) ++i
    else  return [i + 1, j + 1]
  }
};
console.log(twoSum([2, 7, 11, 15], 9))
