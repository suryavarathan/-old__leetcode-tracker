// Last updated: 7/14/2026, 3:27:19 PM
/**************************\U0001f60e**************************/
const solve = (d, c1, c2) => {
  let res = 0;
  const check = (gain, c, i) => {
    const need = Math.ceil(d / gain);
    if (c[i] >= need) return res += need, true;
    res += c[i], d -= c[i] * gain;
  };
  for (let i = 1; i <= 6; i++) {
    if (check(6 - i, c1, i) || check(6 - i, c2, 7 - i)) return res;
  }
  return -1;
};

const minOperations = (a, b) => {
  const c1 = {}, c2 = {};
  for (let i = 1; i <= 6; i++) c1[i] = c2[i] = 0;
  for (let n of a) c1[n]++;
  for (let n of b) c2[n]++;
  let s1 = 0, s2 = 0;
  for (let i = 1; i <= 6; i++) s1 += i * c1[i], s2 += i * c2[i];
  return s1 < s2 ? solve(s2 - s1, c1, c2) : solve(s1 - s2, c2, c1);
};