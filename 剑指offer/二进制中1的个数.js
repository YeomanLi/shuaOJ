function NumberOf1(n)
{
  // write code here
  let res = 0
  while (0 != n) {
    ++res
    n &= (n - 1)
  }
  return res
}