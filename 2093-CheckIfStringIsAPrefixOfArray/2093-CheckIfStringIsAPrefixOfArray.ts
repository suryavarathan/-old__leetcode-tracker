// Last updated: 7/14/2026, 3:23:11 PM
function isPrefixString(s: string, words: string[]) {
    let res = '';
    for (const w of words) {
        if ((res += w).length >= s.length) break;
    }
    return res === s;
}