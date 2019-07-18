const arr = [3, 32, 321]
function PrintMinNumber(numbers) {
  // write code here
  numbers.sort((a, b) => a + b < b + a)
}
PrintMinNumber(arr)
console.log(arr)
