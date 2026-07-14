// Last updated: 7/14/2026, 3:25:20 PM
/**************************\U0001f60e**************************/
function minSwaps(s) {
    let zeros = s.replaceAll('1', '').length;
    let ones = s.length - zeros;

    if (Math.abs(zeros - ones) > 1) return -1;
    function swapString(curr) {
        let swaps = 0;
        for (let char of s) {
            if (char !== curr) swaps += 1;
            curr = `${curr ^ 1}`;
        }
        return swaps / 2;
    }
    if (zeros > ones) return swapString('0');
    if (zeros < ones) return swapString('1');
    return Math.min(swapString('0'), swapString('1'));
};