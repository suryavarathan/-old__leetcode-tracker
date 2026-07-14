# Last updated: 7/14/2026, 3:26:02 PM
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:

        new_str = set(sentence)
        
        if len(new_str) != 26:
            return False
        else:
            return True