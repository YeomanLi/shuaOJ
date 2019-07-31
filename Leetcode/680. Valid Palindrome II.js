/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
  for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return helper(s, i + 1, j) || helper(s, i, j - 1)
    }
  }
  return true
};

var helper = function (s, i, j) {
  for (i, j; i < j; ++i, --j) {
    if (s[i] != s[j]) return false
  }
  return true
}

console.log(validPalindrome("abca"))
