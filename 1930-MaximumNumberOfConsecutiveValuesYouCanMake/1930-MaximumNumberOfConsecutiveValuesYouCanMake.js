// Last updated: 7/14/2026, 3:26:40 PM
/**************************\U0001f60e**************************/
function getMaximumConsecutive(coins) {
  coins.sort((a, b) => a - b);
  let maxConsec = 1;
  for (let num of coins) {
    if (num <= maxConsec) maxConsec += num;
  }
  return maxConsec;
};