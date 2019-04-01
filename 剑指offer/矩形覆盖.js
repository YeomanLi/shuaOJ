function rectCover(number)
{
  // write code here
  if (2 >= number) return number
  let pre = 1, next = 2
  let res
  for (let i = 3; i <= number; ++i) {
    res = pre + next
    pre = next
    next = res
  }
  return res
}