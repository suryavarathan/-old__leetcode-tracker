// Last updated: 7/14/2026, 3:20:36 PM
const STEP = 1 << 18
const MASK = STEP - 1

var dist [100_000]uint32
var seen [1_000_000]uint32
var distgen, seengen uint32

func init() {
	distgen = 1 << 31
	for i := range dist {
		dist[i] = 1 << 31
	}
}

func solveQueries(nums []int, queries []int) []int {
	n := uint32(len(nums))
	seengen += STEP
	distgen -= STEP
	for i := range n * 2 {
		idx := i % n
		v := nums[idx] - 1
		if prev := seen[v]; prev > seengen {
			prev &= MASK
			pidx := prev % n
			d := (i - prev) | distgen
			dist[idx] = min(dist[idx], d)
			dist[pidx] = min(dist[pidx], d)
		}
		seen[v] = i | seengen
	}
	for i, q := range queries {
		if dist[q] >= distgen+n {
			queries[i] = -1
		} else {
			queries[i] = int(dist[q] & MASK)
		}
	}
	return queries
}