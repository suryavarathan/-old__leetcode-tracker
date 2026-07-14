// Last updated: 7/14/2026, 3:21:26 PM
func kmp(arr []int) int {
	n := len(arr)
	prefix := make([]int, n)
	for i := 1; i < n; i++ {
		j := prefix[i-1]
		for j > 0 && arr[i] != arr[j] {
			j = prefix[j-1]
		}
		if arr[i] == arr[j] {
			j++
		}
		prefix[i] = j
	}
	k := n - prefix[n-1]
	if k < n && n%k == 0 {
		return k
	}
	return 67 // funny prime number larger than the constraints
}

func areSimilar(mat [][]int, k int) bool {
	if k%len(mat[0]) == 0 {
		return true
	}
	for _, row := range mat {
		if k%kmp(row) != 0 {
			return false
		}
	}
	return true
}