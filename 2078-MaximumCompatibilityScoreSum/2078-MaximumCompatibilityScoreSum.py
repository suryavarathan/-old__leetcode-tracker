# Last updated: 7/14/2026, 3:23:36 PM
class Solution:
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        pair_score = defaultdict(int)
        n = len(students)

        # build compatibilty score for every possible student-mentor pair
        for i in range(n):
            for j in range(n):
                pair_score[i, j] = sum(s_ans == m_ans for s_ans, m_ans in zip(students[i], mentors[j]))
        
        # try to pair student[i] with every unused mentor
        # mentor[j] is unused if 'j'th bit in mask is '1'
        @cache
        def dfs(i, mask):
            if i == len(students):
                return 0
            return max(dfs(i + 1, mask - (1 << j)) + pair_score[i, j] for j in range(n) if (1 << j) & mask)
                    
        return dfs(0, (1 << len(students)) - 1)