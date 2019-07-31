/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
  const set = 'aeiouAEIOU'
  let res = s.split('')
  let start = 0, end = s.length - 1
  while (start < end) {
    while (start < end && !set.includes(res[start]))  ++start
    while (start < end && !set.includes(res[end]))  --end
    let temp = res[start]
    res[start] = res[end]
    res[end] = temp
    ++start
    --end
  }
  return res.join('')
};
console.log(reverseVowels('leetcode'))
