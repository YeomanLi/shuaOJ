const arr = []
function Insert(num) {
  // write code here
  arr.push(num)
  // for (let i = arr.length - 2; arr[i] > num; --i) {
  //   [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
  // }
  arr.sort((a, b) => a - b)
}

function GetMedian() {
  // write code here
  if (arr.length % 2 === 0)
    return (arr[arr.length / 2] + arr[arr.length / 2 - 1]) / 2
  else
    return arr[(arr.length - 1) / 2]
}
