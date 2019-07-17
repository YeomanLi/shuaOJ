function MoreThanHalfNum_Solution(numbers)
{
  // write code here
  let cnt = 0
  let res
  for (let i = 0; i < numbers.length; ++i) {
    if (!cnt) res = numbers[i]
    cnt = numbers[i] === res ? cnt + 1 : cnt - 1
  }
  cnt = 0
  for (let i = 0; i < numbers.length; ++i) {
    cnt = numbers[i] === res ? cnt + 1 : cnt
  }
  if (cnt * 2 <= numbers.length)  res = 0
  return res
}
