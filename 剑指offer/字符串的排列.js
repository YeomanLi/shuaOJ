function Permutation(str)
{
  // write code here
  let res = []
  if (!str.length)  return res
  arr = str.split('') //  转化为字符串数组
  res = Permutate(arr, 0, res)
  res = [...new Set(res)] //  去重
  res.sort()  //  排序
  return res
}

function Permutate (arr, index, res) {
  if (arr.length === index) {
    let str = ''
    for (let i = 0; i < arr.length; i++)
      str += arr[i]
    return res.push(str)
  }
  for (let i = index; i < arr.length; i++) {
    [arr[index], arr[i]] = [arr[i], arr[index]] // 交换
    Permutate(arr, index + 1, res)
    [arr[index], arr[i]] = [arr[i], arr[index]] // 交换
  }
  return res
}

const res = Permutation('ab')
console.log(res)
