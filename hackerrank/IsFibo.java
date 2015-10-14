// "Is Fibo" HackerRank Challenge
// https://www.hackerrank.com/challenges/is-fibo
// Category: Algorithms

package com.lukereichold;

import java.util.ArrayList;
import java.util.Scanner;

public class IsFibo {

    private static ArrayList<Double> fib;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        computeFibonacci();

        for (int i = 0; i < numCases; i++) {
            double originalN = in.nextDouble();
            if (fib.contains(Double.valueOf(originalN))) {
                System.out.println("IsFibo");
            } else {
                System.out.println("IsNotFibo");
            }
        }
    }

    // Pre-compute all Fibonacci numbers less than the constraint N <= 10^10 (faster since there's only ~ 50)
    private static void computeFibonacci() {
        fib = new ArrayList<Double>();
        fib.add(Double.valueOf(0));
        fib.add(Double.valueOf(1));

        int i = 1;
        double max = Math.pow(10, 10);
        while (max > fib.get(i)) {
            i++;
            fib.add(Double.valueOf(fib.get(i - 1) + fib.get(i - 2)));
        }
    }
}