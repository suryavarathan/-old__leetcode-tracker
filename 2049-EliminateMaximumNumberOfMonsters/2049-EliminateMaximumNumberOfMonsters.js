// Last updated: 7/14/2026, 3:24:06 PM
/**************************\U0001f60e**************************/
function eliminateMaximum(distance, speed) {
    const n = distance.length;
    const time = new Array(n);

    for (let i = 0; i < n; i++) {
        time[i] = distance[i] / speed[i];
    }

    time.sort((a, b) => a - b);
    let kills = 0;

    for (let i = 0; i < n; i++) {
        if (time[i] - i > 0) {
            kills++;
        } else {
            return kills;
        }
    }

    return kills;
}