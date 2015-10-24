// "Utopian Tree" HackerRank Challenge
// https://www.hackerrank.com/challenges/utopian-tree
// Category: Algorithms

package com.lukereichold;

import java.util.Scanner;

public class UtopianTree {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();

        for (int i = 0; i < cases; i++) {
            int numCycles = in.nextInt();
            int height = 1;

            for (int j=1; j <= numCycles; j++) {
                height = (j % 2 == 0) ? height+1 : height*2;
            }
            System.out.println(height);
        }
    }
}