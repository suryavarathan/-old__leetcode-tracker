// Last updated: 7/14/2026, 3:23:01 PM
/**************************\U0001f60e**************************/
function minNonZeroProduct(p) {
    const mod = (bInt) => bInt % BigInt((10 ** 9) + 7);
    const twoP = 1n << BigInt(p);
    let mult0 = twoP - 2n;
    let Exp0 = mult0 >> 1n;
    const mult1 = mod(twoP - 1n);
    let mult0Exp0 = 1n;
    while (Exp0 > 0n) {
        if ((Exp0 & 1n) === 1n) {
            mult0Exp0 = mod(mult0Exp0 * mult0);
        }
        mult0 = mod(mult0 * mult0);
        Exp0 >>= 1n;
    }
    return Number(mod(mult0Exp0 * mult1));
};