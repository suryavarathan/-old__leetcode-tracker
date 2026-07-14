// Last updated: 7/14/2026, 3:29:38 PM
/**************************\U0001f60e**************************/
function stoneGameVI(aliceValues, bobValues) {
    for (let i = 0; i < aliceValues.length; i++) {
        aliceValues[i] = [aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]];
    }
    aliceValues.sort((x, y) => y[0] - x[0]);
    let x = 0
    let y = 0
    for (let i = 0; i < aliceValues.length; i += 2) {
        x += aliceValues[i][1];
    }
    for (let i = 1; i < aliceValues.length; i += 2) {
        y += aliceValues[i][2];
    }
    return x === y ? 0 : x > y ? 1 : -1
};