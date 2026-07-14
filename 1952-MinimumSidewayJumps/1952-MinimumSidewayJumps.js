// Last updated: 7/14/2026, 3:26:14 PM
/**************************😎**************************/
function minSideJumps(obstacles) {
    const MAX = 10 ** 6;
    let current = [MAX, 0, MAX];
    let next = [0, 0, 0];
    let lastLaneBlocked = -1;
    for (let i = 1; i < obstacles.length; i += 1) {
        const laneBlocked = obstacles[i] - 1;
        for (let currentLane = 0; currentLane < 3; currentLane += 1) {
            next[currentLane] = MAX;
            if (laneBlocked === currentLane) continue;
            for (let previousLane = 0; previousLane < 3; previousLane += 1) {
                const jumpCost = currentLane === previousLane ? 0 : 1;
                const extraJump = lastLaneBlocked === currentLane && laneBlocked === previousLane ? 1 : 0;
                next[currentLane] = Math.min(
                    next[currentLane],
                    current[previousLane] + jumpCost + extraJump,
                );
            }
        }
        lastLaneBlocked = laneBlocked;
        [current, next] = [next, current];
    }
    return Math.min(...current);
};