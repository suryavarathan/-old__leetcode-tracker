// Last updated: 7/14/2026, 3:24:20 PM
/**************************\U0001f60e**************************/
function sumGame(num) {
    let n = num.length
    let leftSum = 0
    let rightSum = 0
    let leftMark = 0
    let rightMark = 0
    for (let i = 0; i < n; i++) {
        if (i < n / 2) {
            if (num[i] === '?') {
                leftMark += 1
            } else {
                leftSum += Number(num[i])
            }
        } else {
            if (num[i] === '?') {
                rightMark += 1
            } else {
                rightSum += Number(num[i])
            }
        }

    }
    if (leftMark === rightMark) {
        return leftSum !== rightSum
    } else if (leftMark < rightMark) {
        let diff = rightMark - leftMark
        let alice_move = diff % 2 == 1 ? Math.floor(diff / 2) + 1 : diff / 2
        let bob_move = diff - alice_move
        if (rightSum + 9 * alice_move > leftSum) return true
        if (rightSum + 9 * bob_move < leftSum) return true
        return false
    } else {
        let diff = leftMark - rightMark
        let alice_move = diff % 2 == 1 ? Math.floor(diff / 2) + 1 : diff / 2
        let bob_move = diff - alice_move
        if (leftSum + 9 * alice_move > rightSum) return true
        if (leftSum + 9 * bob_move < rightSum) return true
        return false
    }
};