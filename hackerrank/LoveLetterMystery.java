// "Love-Letter Mystery" HackerRank Challenge
// https://www.hackerrank.com/challenges/the-love-letter-mystery
// Category: Algorithms

package com.lukereichold;

import java.util.Scanner;

public class LoveLetterMystery {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < cases; i++) {

            String word = in.nextLine();
            int numOpsNeeded = 0;

            if (word.length() > 1) {

                // Compare characters of second half of word to first half
                int beginningOfSecondHalf = (int) Math.ceil(word.length() / 2.0);

                for (int j = beginningOfSecondHalf; j < word.length(); j++) {

                    int offset = (j - beginningOfSecondHalf) + 1;
                    if (word.length() % 2 != 0) {
                        offset++;
                    }
                    numOpsNeeded += Math.abs(word.charAt(j) - word.charAt(beginningOfSecondHalf - offset));
                }
            }
            System.out.println(numOpsNeeded);
        }
    }
}