// Last updated: 7/14/2026, 3:19:44 PM
class Solution {
    func maxWalls(_ robots: [Int], _ distance: [Int], _ walls: [Int]) -> Int {
        let n = robots.count
        if n == 0 { return 0 }

        // Pair robot position with its distance, then sort by robot position.
        let robotDist: [(pos: Int, dist: Int)] = zip(robots, distance)
            .map { (pos: $0, dist: $1) }
            .sorted { $0.pos < $1.pos }

        let walls = walls.sorted()
        let m = walls.count

        var rightPtr = 0
        var leftPtr = 0
        var curPtr = 0
        var robotPtr = 0

        var prevRight = 0
        var subLeft = 0
        var subRight = 0

        for i in 0..<n {
            let robotPos = robotDist[i].pos
            let robotRange = robotDist[i].dist

            // pos1 = first wall strictly > robotPos
            while rightPtr < m && walls[rightPtr] <= robotPos {
                rightPtr += 1
            }
            let pos1 = rightPtr

            // pos2 = first wall >= robotPos
            while curPtr < m && walls[curPtr] < robotPos {
                curPtr += 1
            }
            let pos2 = curPtr

            // Left shot range: [leftBound ... robotPos]
            let leftBound: Int
            if i > 0 {
                leftBound = max(robotPos - robotRange, robotDist[i - 1].pos + 1)
            } else {
                leftBound = robotPos - robotRange
            }

            while leftPtr < m && walls[leftPtr] < leftBound {
                leftPtr += 1
            }
            let leftPos = leftPtr
            let currentLeft = pos1 - leftPos

            // Right shot range: [robotPos ... rightBound]
            let rightBound: Int
            if i + 1 < n {
                rightBound = min(robotPos + robotRange, robotDist[i + 1].pos - 1)
            } else {
                rightBound = robotPos + robotRange
            }

            while rightPtr < m && walls[rightPtr] <= rightBound {
                rightPtr += 1
            }
            let rightPos = rightPtr
            let currentRight = rightPos - pos2

            // Number of walls in [prevRobotPos ... robotPos]
            var currentNum = 0
            if i > 0 {
                while robotPtr < m && walls[robotPtr] < robotDist[i - 1].pos {
                    robotPtr += 1
                }
                let pos3 = robotPtr
                currentNum = pos1 - pos3
            }

            if i == 0 {
                subLeft = currentLeft
                subRight = currentRight
            } else {
                let newSubLeft = max(
                    subLeft + currentLeft,
                    subRight - prevRight + min(currentLeft + prevRight, currentNum)
                )

                let newSubRight = max(
                    subLeft + currentRight,
                    subRight + currentRight
                )

                subLeft = newSubLeft
                subRight = newSubRight
            }

            prevRight = currentRight
        }

        return max(subLeft, subRight)
    }
}