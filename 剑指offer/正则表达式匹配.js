/**
 * 三种情况：
 * 1. 模式当前字符为普通字母，相等则都后移一位，不等返回false
 * 2. 模式当前字符为'.'，模式、字符串均后移一位
 * 3. 模式当前字符为'*'，继续分类：
 *    1. 
 */

//s, pattern都是字符串
var sLen, patternLen

function match(s, pattern)
{
  // write code here
  sLen = s.length
  patternLen = pattern.length
  let p = 0, q = 0
  return solve(s, pattern, p, q)
}

function solve (s, pattern, p, q) {
  // 两个指针同时到末尾，成功
  // if (p == sLen && q == patternLen) return true
  if (q == patternLen)  return true
  // 字符串末尾，模式没有末尾，失败
  if (p == sLen && q != patternLen) return false
  
}