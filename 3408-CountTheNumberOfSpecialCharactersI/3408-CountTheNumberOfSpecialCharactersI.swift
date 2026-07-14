// Last updated: 7/14/2026, 3:20:59 PM
class Solution {
    func numberOfSpecialChars(_ word: String) -> Int {
        var seen: Set<Character> = []
        for letter in word {
            seen.insert(letter)
        }

        var result = 0
        for letter in seen {
            if letter.isLowercase,
                seen.contains(Character(letter.uppercased())) {
                result += 1
            }
        }

        return result
    }
}