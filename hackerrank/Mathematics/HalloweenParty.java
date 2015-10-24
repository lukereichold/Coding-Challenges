// "Halloween Party" HackerRank Challenge
// https://www.hackerrank.com/challenges/halloween-party
// Category: Algorithms

package com.lukereichold;

import java.util.*;

public class HalloweenParty {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < cases; i++) {
            int numCuts = in.nextInt();

            double numPieces = Math.floor(numCuts / 2.0);
            numPieces *= (numCuts - numPieces);
            System.out.printf("%.0f\n", numPieces);
        }
    }
}