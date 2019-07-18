let str = "657842961";
let arr = str.split("");

Array.prototype.Bubble_Sort = function () {
  let arr = this
  for (let i = arr.length - 1; i > 0; --i) {
    for (let j = 0; j < i; ++j) {
      if (arr[j] > arr[j + 1]) [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
    }
  }
}

function Merge (left, right) {
  const res = []
  while (0 < left.length && 0 < right.length)
    res.push(left[0] <= right[0] ? left.shift() : right.shift())
  return res.concat(left, right)
}

Array.prototype.Merge_Sort = function () {
  const arr = this
  const len = arr.length
  if (2 > len)  return arr
  const mid = Math.floor(len / 2)
  const left = arr.splice(0, mid)
  const right = arr
  return Merge(left.Merge_Sort(), right.Merge_Sort())
}

Array.prototype.Partition = function (left, right) {
  const arr = this
  let key = arr[left]
  while (left < right) {
    while (arr[right] >= key && right > left)
      right--
    [arr[left], arr[right]] = [arr[right], arr[left]]
    while (arr[left] <= key && left < right) 
      left++
    [arr[left], arr[right]] = [arr[right], arr[left]]
  }
  return left
}

Array.prototype.Quick_Sort = function (left = 0, right = this.length - 1) {
  const arr = this
  if (2 > arr.length) return
  let key = arr.Partition(left, right)
  if (left < key) arr.Quick_Sort(left, key - 1)
  if (right > key)  arr.Quick_Sort(key + 1, right)
}

arr.Quick_Sort()
console.log(arr)
