const numbers = [2, 3, 1, 0, 2, 5, 3]
const duplication = []
function duplicate(numbers, duplication)
{
    // write code here
    //这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    //函数返回True/False
    /*let res = false
    for(let i = 0; i < numbers.length; ++i) {
        if (numbers.indexOf(numbers[i]) != numbers.lastIndexOf(numbers[i])) {
            duplication[0] = numbers[i]
            res = true
            break
        }
    }
    return res*/
    for (let i = 0; i < numbers.length; ++i ) {
        while(numbers[i] != i) {
            // console.log(`${numbers[i]} + ${numbers[numbers[i]]}`)
            if (numbers[i] == numbers[numbers[i]]) {
                duplication[0] = numbers[i]
                return true
            }
            let temp = numbers[i]
            numbers[i] = numbers[numbers[i]]
            // 这里注意要使用temp，不能还是使用numbers[i]
            numbers[temp] = temp
        }
    }
    return false
}
console.log(duplicate(numbers, duplication))
console.log(duplication[0])