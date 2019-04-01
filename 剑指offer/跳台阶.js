function jumpFloor(number)
{
  // write code here
  if (2 >= number)  return number
  let res
  let pre = 1, next = 2
  for (let i = 3; i <= number; ++i) {
    res = pre + next
    pre = next
    next = res
  }
  return res
}