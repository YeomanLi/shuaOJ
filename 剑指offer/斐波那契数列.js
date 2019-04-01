function Fibonacci(n)
{
  // write code here
  if (0 == n) return 0
  else if (2 >= n) return 1
  let pre = 1
  let next = 1
  let res
  for (let i = 3; i <= n; ++i) {
    res = pre + next
    pre = next
    next = res
  }
  return res
}