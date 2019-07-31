/**
 * @param {string} s
 * @param {string[]} d
 * @return {string}
 */
var findLongestWord = function(s, d) {
  let res = ''
  for (let target of d) {
    if (res.length > target.length || (res.length === target.length && res < target)) continue
    if (isSubstr(s, target))  res = target
  }
  return res
};

var isSubstr = function (s, target) {
  let i = 0, j = 0
  while (i < s.length && j < target.length) {
    if (s[i] === target[j]) ++j
    ++i
  }
  return j === target.length
}