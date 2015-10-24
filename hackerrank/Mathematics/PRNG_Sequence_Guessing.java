// "PRNG Sequence Guessing" HackerRank Challenge
// https://www.hackerrank.com/challenges/prng-sequence-guessing
// Category: Algorithms > Cryptography

package com.lukereichold;

import java.util.Random;
import java.util.Scanner;

public class PRNG_Sequence_Guessing {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < cases; i++) {
            int startTime = in.nextInt();
            int endTime = in.nextInt();
            int[] values = new int[10];

            for (int j = 0; j < 10; j++) {
                values[j] = in.nextInt();
            }

            // Iterate over all possible timestamp seeds
            for (int seed = startTime; seed <= endTime; seed++) {
                Random r = new Random(seed);
                boolean wrongSeed = false;
                for (int j = 0; j < 10; j++) {
                    if (r.nextInt(1000) != values[j]) {
                        wrongSeed = true;
                        break;
                    }
                }
                // If we got here, then we found the seed that generates the given values
                if (!wrongSeed) {
                    System.out.print(seed + " ");
                    for (int j = 0; j < 10; j++) {
                        System.out.print(r.nextInt(1000) + " ");
                    }
                    System.out.println();
                    break; // Don't attempt to check subsequent seeds
                }
            }
        }
    }
}