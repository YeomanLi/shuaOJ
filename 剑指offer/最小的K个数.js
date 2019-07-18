function GetLeastNumbers_Solution(input, k)
{
  // write code here
  if (!input.length || k > input.length || 1 > k)
    return []
  const left = 0
  const right = input.length - 1
  let key = Partition(input, left, right)
  while (key != k - 1) {
    if (key > k - 1)
      key = Partition(input, left, key - 1)
    else
      key = Partition(input, key + 1, right)
  }
  const res = input.slice(0, k)
  res.sort((a, b) => a - b)
  return res
}

function Partition (arr, left, right) {
  let key = arr[left]
  while (left < right) {
    while (arr[right] >= key && left < right)
      right--
    [arr[left], arr[right]] = [arr[right], arr[left]]
    while (arr[left] < key && left < right)
      left++
    [arr[left], arr[right]] = [arr[right], arr[left]]
  }
  return left
}

Array.prototype.Partition = function (left = 0, right = this.length - 1) {
  const arr = this
  let key = arr[left]
  while (left < right) {
    while (arr[right] >= key && left < right) right--
    [arr[left], arr[right]] = [arr[right], arr[left]]
    while (arr[left] <= key && left < right) left++
    [arr[left], arr[right]] = [arr[right], arr[left]]
  }
  return left
}
