// Last updated: 7/14/2026, 3:27:37 PM
class Solution {
    fun checkPowersOfThree(n: Int): Boolean {
        var rest = n
        var number = Math.pow(3.0, 14.0).toInt()
        for (i in 0 until 15) {
            // println("${rest} ${number}")
            if (rest >= number) {
                rest -= number
            }
            number /= 3
        }
        return rest == 0
    }
}