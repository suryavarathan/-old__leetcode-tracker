// Last updated: 7/14/2026, 3:28:50 PM
/**************************\U0001f60e**************************/
function eatenApples(A, D) {
    let time = new Array(40001), ans = 0, last = A.length
    for (let i = 0, j = Infinity; i <= last; i++) {
        if (j < i) j = i
        if (A[i]) {
            let exp = i + D[i] - 1
            if (time[exp]) time[exp] += A[i]
            else time[exp] = A[i]
            if (exp < j) j = exp
            if (exp > last) last = exp
        }
        while (!time[j] && j < last) j++
        if (time[j]) ans++, time[j]--
    }
    return ans
};