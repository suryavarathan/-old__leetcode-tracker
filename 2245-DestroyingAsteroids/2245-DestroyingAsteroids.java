// Last updated: 7/14/2026, 3:22:09 PM
class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);

        long currMass = mass;

        for (int asteroid : asteroids) {
            if (asteroid > currMass) {
                return false;
            }

            currMass += asteroid;
        }

        return true;

    }
}