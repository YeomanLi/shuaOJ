function hasPath(matrix, rows, cols, path)
{
  // write code here
  if (null == matrix || 0 == matrix.length || 1 > rows || 1 > cols || null == path || 0 == path.length) return false
  let visited = []
  for (let i = 0; i < rows; ++i) {
    visited[i] = []
    for (let j = 0; j < cols; ++j) {
      visited[i][j] = false
    }
  }
  for (let i = 0; i < rows; ++i) {
    for (let j = 0; j < cols; ++j) {
      if (helper(matrix, rows, cols, i, j, path, visited))
        return true
    }
  }
  return false
}

function helper (matrix, rows, cols, top, left, path, visited) {
  if (0 <= left && cols > left && 0 <= top && rows > top && !visited[top][left] && path.charAt(0) == matrix[cols * top + left]) {
    visited[top][left] = true
    if (1 == path.length || helper(matrix, rows, cols, top + 1, left, path.slice(1), visited))  return true
    if (1 == path.length || helper(matrix, rows, cols, top - 1, left, path.slice(1), visited))  return true
    if (1 == path.length || helper(matrix, rows, cols, top, left + 1, path.slice(1), visited))  return true
    if (1 == path.length || helper(matrix, rows, cols, top, left - 1, path.slice(1), visited))  return true
    visited[top][left] = false
  }
  return false
}

const params = ["ABCESFCSADEE",3,4,"ABCB"]
console.log(hasPath(...params))