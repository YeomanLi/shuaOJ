// 暴力解法
function NumberOf1Between1AndN_Solution(n) {
  // write code here
  let res = 0
  for (let i = 1; i <= n; ++i) {
    let num = i
    while (num) {
      if (1 === num % 10)
        ++res
      num = Math.floor(num / 10)
    }
  }
  return res
}
console.log(NumberOf1Between1AndN_Solution(13))
