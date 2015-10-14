// "Find Digits" HackerRank Challenge
// https://www.hackerrank.com/challenges/find-digits
// Category: Algorithms

package com.lukereichold;

import java.util.Scanner;

public class FindDigits {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int originalN = in.nextInt();
            int numDigitsThatDivideExactly = 0;
            int n = originalN;

            while (n != 0) {
                int digit = n % 10;
                if (digit != 0 && originalN % digit == 0)
                    numDigitsThatDivideExactly++;
                n /= 10;
            }
            System.out.println(numDigitsThatDivideExactly);
        }
    }
}