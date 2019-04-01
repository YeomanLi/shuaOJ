let str = 'We Are Happy.'
function replaceSpace (str) {
  /**
   * 首先统计str中的空格数
   * 注意字符串的原长度和后来的长度区分开来
   * 或者直接使用正则表达式
   * !!!!JavaScript是不可以直接通过[]来改变字符串的指定位置的，必须先split为数组，再join
   *  */ 
  let initialLength = str.length
  for (let i = 0; i < initialLength; ++i ) {
    if (' ' == str[i]) {
      str += '  '
    }
  }
  str = str.split('')
  let p1 = initialLength - 1
  let p2 = str.length - 1
  for (p1; p1 > -1; --p1) {
    if (' ' != str[p1]) {
      str[p2--] = str[p1]
    } else {
      str[p2--] = '0'
      str[p2--] = '2'
      str[p2--] = '%'
    }
  }
  str = str.join('')
  return str
  // return str.replace(/\s/g, '%20')
}
const res = replaceSpace(str)
console.log(res)
