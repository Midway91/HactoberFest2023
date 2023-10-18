/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    if(rowIndex === 0) return [1]
    if(rowIndex === 1) return [1,1]
    let currentRow = [1,1]
    let currentIndex = 2
    while(currentIndex <= rowIndex) {
        const nextRow = [1]
        let start = 0
        while(start < currentRow.length - 1) {
            nextRow.push(currentRow[start] + currentRow[start + 1])
            start++
        } 
        nextRow.push(1)
        currentRow = nextRow
        currentIndex++
    }
    return currentRow
}
