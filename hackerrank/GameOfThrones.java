// "Game of Thrones - I" HackerRank Challenge
// https://www.hackerrank.com/challenges/game-of-thrones
// Category: Algorithms

package com.lukereichold;

import java.util.HashMap;
import java.util.Scanner;

public class GameOfThrones {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String result = isPalindrome(in.nextLine()) ? "YES" : "NO";
        System.out.println(result);
    }

    private static boolean isPalindrome(String word) {

        HashMap<Character, Boolean> parityMap = new HashMap<Character, Boolean>();

        for (char c : word.toCharArray()) {
            if (parityMap.containsKey(c)) {
                parityMap.put(c, !parityMap.get(c)); // Flip parity if we've seen this character before
            } else {
                parityMap.put(c, false); // Add new character to map (1 is odd, aka 'false')
            }
        }

        boolean odd_seen = false;
        for (Boolean parity : parityMap.values()) {
            if (parity == false) {
                if (odd_seen) return false;
                else odd_seen = true;
            }
        }
        return true;
    }
}