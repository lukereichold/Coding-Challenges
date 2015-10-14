// "Keyword Transposition Cipher" HackerRank Challenge
// https://www.hackerrank.com/challenges/keyword-transposition-cipher
// Category: Algorithms > Cryptography

package com.lukereichold;

import java.util.*;

public class KeywordTranspositionCipher {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < cases; i++) {

            String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            String keyword = removeDuplicates(in.nextLine());
            List<List<Character>> columns = new ArrayList<List<Character>>();
            TreeMap<Character, Integer> map = new TreeMap<Character, Integer>();

            for (int j = 0; j < keyword.toCharArray().length; j++) {
                Character c = keyword.toCharArray()[j];
                map.put(c, j);

                List<Character> charList = new ArrayList<Character>();
                charList.add(c);
                columns.add(j, charList);
            }

            String remainingAlphabet = removeKeywordCharactersFromAlphabet(keyword, alphabet);
            for (int j = 0; j < remainingAlphabet.length(); j++) {
                columns.get(j % keyword.length()).add(remainingAlphabet.charAt(j));
            }

            List<Character> cipherAlphabet = new ArrayList<Character>();
            for (Integer index : map.values()) {
                List column = columns.get(index);
                for (int j = 0; j < column.size(); j++) {
                    cipherAlphabet.add((Character)column.get(j));
                }
            }

            for (char c : in.nextLine().toCharArray()) {
                if (c != ' ') {
                    System.out.print(alphabet.charAt(cipherAlphabet.indexOf(new Character(c))));
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    private static String removeKeywordCharactersFromAlphabet(String keyword, String alphabet) {

        StringBuilder sb = new StringBuilder();
        for (char c : alphabet.toCharArray()) {
            if (!keyword.contains(String.valueOf(c))) {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private static String removeDuplicates(String inString) {

        Set<Character> charSet = new LinkedHashSet<Character>();
        for (char c : inString.toCharArray()) {
            charSet.add(c);
        }

        StringBuilder sb = new StringBuilder();
        for (Character character : charSet) {
            sb.append(character);
        }
        return sb.toString();
    }
}