// Last updated: 7/14/2026, 3:20:53 PM
func numberOfSubmatrices(grid [][]byte) int {
    // count X and Y cells until each column
    xs := make([]int, len(grid[0]))
    ys := make([]int, len(grid[0]))
    cnt := 0
    for i:=0; i<len(grid); i++ {
        // count X and Y cells in the next row
        x,y := 0,0
        for j:=0; j<len(grid[0]); j++ {
            if grid[i][j] == 'X' { x++ }
            if grid[i][j] == 'Y' { y++ }
            // update the column counts for the actual row
            xs[j] += x
            ys[j] += y
            // check if the frequency is equal
            if xs[j] == ys[j] && xs[j] > 0 { cnt++ }
        }
    }
    return cnt
}