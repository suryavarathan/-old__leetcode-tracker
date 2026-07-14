# Last updated: 7/14/2026, 3:21:55 PM
class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        l = r = startIndex
        n = len(words)
        steps = 0

        while steps <= n // 2:
            if words[l] == target or words[r] == target: # step = 0 is also considered
                return steps

            l = (l - 1 + n) % n
            r = (r + 1) % n
            steps += 1

        return -1
        