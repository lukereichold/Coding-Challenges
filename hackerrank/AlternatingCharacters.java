// "Alternating Characters" HackerRank Challenge
// https://www.hackerrank.com/challenges/alternating-characters
// Category: Algorithms

package com.lukereichold;

import java.util.Scanner;

public class AlternatingCharacters {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < cases; i++) {
            int numCharactersToRemove = 0;
            char lastChar = 'x';
            for (char c : in.nextLine().toCharArray()) {
                if (c == lastChar)
                    numCharactersToRemove++;
                lastChar = c;
            }
            System.out.println(numCharactersToRemove);
        }
    }
}