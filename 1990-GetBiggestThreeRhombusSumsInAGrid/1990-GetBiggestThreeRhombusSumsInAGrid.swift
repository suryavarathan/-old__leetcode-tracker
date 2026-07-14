// Last updated: 7/14/2026, 3:25:23 PM
class Solution {
    func getBiggestThree(_ grid: [[Int]]) -> [Int] {
        let n = grid.count
        let m = grid[0].count
        var sums = Set<Int>()

        func calc(_ x: Int, _ y: Int) {
            let maxSize = min(y + 1, m - y, (n - x + 1) / 2)

            for k in 0..<maxSize {
                if k == 0 {
                    sums.insert(grid[x][y])
                    continue
                }

                var s = 0
                var i = x
                var j = y

                for _ in 0..<k {
                    s += grid[i][j]
                    i += 1
                    j -= 1
                }

                for _ in 0..<k {
                    s += grid[i][j]
                    i += 1
                    j += 1
                }

                for _ in 0..<k {
                    s += grid[i][j]
                    i -= 1
                    j += 1
                }

                for _ in 0..<k {
                    s += grid[i][j]
                    i -= 1
                    j -= 1
                }

                sums.insert(s)
            }
        }

        for i in 0..<n {
            for j in 0..<m {
                calc(i, j)
            }
        }

        return sums.sorted(by: >).prefix(3).map { $0 }
    }
}