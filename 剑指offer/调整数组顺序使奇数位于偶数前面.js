// [1,2,3,4,5,6,7]
// [1,3,5,7,2,4,6]
const arr = [1,2,3,4,5,6,7]
function reOrderArray(array)
{
  // write code here
  // 首先统计出所有的奇数个数
  let oddNum = 0
  array.forEach(number => {
    if (1 == number % 2)  ++oddNum
  })
  arr.forEach(number => {
    if (0 == number % 2)
      array[oddnum++] = number
  })
}
console.log(reOrderArray(arr))