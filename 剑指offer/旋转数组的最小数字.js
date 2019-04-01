function minNumberInRotateArray(rotateArray)
{
  // write code here
  if (null == rotateArray || 0 == rotateArray.length) return 0
  let left = 0, right = rotateArray.length - 1, mid = 0
  // 二分法
  while (rotateArray[left] >= rotateArray[right]) {
    if (1 == right - left)  {
      mid = right
      break
    }
    mid = Number.parseInt((left + right) / 2)
    if (rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right]) {
      return minNumber(rotateArray, left, right)
    } else if (rotateArray[mid] >= rotateArray[left]) {
      left = mid
    } else {
      right = mid
    }
  }
  return rotateArray[mid]
}

function minNumber(rotateArray, left, right) {
  for (let i = left; i <= right; ++i) {
    if (rotateArray[i] > rotateArray[i + 1])
      return rotateArray[i + 1]
  }
  return rotateArray[left]
}
// const test = [3, 4, 5, 1, 2]
const test = [6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335]
console.log(minNumberInRotateArray(test))