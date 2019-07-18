const array = [6, -3, -2, 7, -15, 1, 2, 2]
function FindGreatestSumOfSubArray(array) {
  // write code here
  let sum = 0
  let res = Number.NEGATIVE_INFINITY
  for (let n of array) {
    sum = sum <= 0 ? n : sum + n
    res = Math.max(sum, res)
  }
  return res
}
let res = FindGreatestSumOfSubArray(array)
console.log(res)
