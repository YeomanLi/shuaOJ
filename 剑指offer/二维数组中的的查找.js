function Find(target, array)
{
    // write code here
    /* solution 1
    for (let i = 0; i < array.length; ++i) {
        for (let j = 0; j < array[i].length; ++j) {
            if (array[i][j] == target)
                return true
        }
    }
    return false*/

    /**
     * solution 2
     * 根据规律缩小查找的范围
     * 千万要注意数组空的判断！！！
     */
    if (null == array || 0 == array.length || undefined == array || 0 == array[0].length)    return false
    const len = array.length
    let top = 0
    let right = len - 1
    while((0 <= top && len > top) && (0 <= right && len > right)) {
        const temp = array[top][right]
        if (temp > target)    --right
        else if (temp < target)    ++top
        else    return true
    }
    return false
}