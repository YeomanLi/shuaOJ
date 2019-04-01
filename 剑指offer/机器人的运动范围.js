function movingCount(threshold, rows, cols)
{
  // write code here
  if (0 >= threshold || 0 > rows || 0 > cols) return 0
  let top = 0, left = 0
  const visited = []
  for (let i = 0; i < rows; ++i) {
    visited[i] = []
    for (let j = 0; j < cols; ++j) {
      visited[i][j] = false
    }
  }
  let res = solve(threshold, rows, cols, top, left, visited)
  return res
}

function solve (threshold, rows, cols, top, left, visited) {
  if (0 > top || rows <= top || 0 > left || cols <= left || visited[top][left] || !checkSum(top, left, threshold)) {
    return 0
  }
  visited[top][left] = true
  let res = 1
  res += solve(threshold, rows, cols, top + 1, left, visited)
  res += solve(threshold, rows, cols, top - 1, left, visited)
  res += solve(threshold, rows, cols, top, left + 1, visited)
  res += solve(threshold, rows, cols, top, left - 1, visited)
  return res
}

function checkSum(top, left, threshold) {
  let str = top + '' + left
  str = str.split("")
  let res = 0
  str.forEach(item => { res += Number.parseInt(item) })
  return res <= threshold
}
console.log(movingCount(5, 10, 10))
// 5,10,10