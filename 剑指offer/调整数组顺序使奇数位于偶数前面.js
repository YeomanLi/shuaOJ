// [1,2,3,4,5,6,7]
// [1,3,5,7,2,4,6]
const arr = [1,2,3,4,5,6,7]
// function reOrderArray(array)
// {
//   // write code here
//   const res = []
//   let oddNum = 0
//   let pos = 0
//   array.forEach(number => {
//     if (1 == number % 2)  ++oddNum
//   })
//   array.forEach(number => {
//     if (0 == number % 2)  res[oddNum++] = number
//     else  res[pos++] = number
//   })
//   return res
// }

// 法二，偶数冒泡
function reOrderArray(array) {
  for (let i = array.length - 1; i > 0; --i) {
    for (let j = 0; j < i; ++j) {
      if (0 == array[j] % 2 && 1 == array[j + 1] % 2) {
        let temp = array[j]
        array[j] = array[j + 1]
        array[j + 1] = temp
      }
    }
  }
  return array
}
console.log(reOrderArray(arr))