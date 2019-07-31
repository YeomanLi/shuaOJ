/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    let start = 0, end = Math.floor(Math.sqrt(c))
    while (start <= end) {
        const res = start * start + end * end
        if (res > c)    --end
        else if (res < c) ++start
        else    return true
    }
    return false
};
console.log(judgeSquareSum(4))
