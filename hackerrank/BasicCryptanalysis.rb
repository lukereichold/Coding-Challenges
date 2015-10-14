#!/usr/bin/env ruby

# "Basic Cryptanalysis" HackerRank Challenge
# https://www.hackerrank.com/challenges/basic-cryptanalysis
# Category: Algorithms > Cryptography

# Task: Given a piece of text encoded with a simple monoalphabetic substitution cipher, 
# use basic cryptanalytic techniques to attempt to recover the original plaintext. 
# You will be provided with a special dictionary file that you can read from dictionary.lst, 
# which will consist of one word per line.
# --------

dictionaryWords = Array.new
cipherWords = gets.chomp.split

File.open('dictionary.lst', 'r') do |f|
  while line = f.gets
    dictionaryWords.push(line)
  end
end


for i in 0..25
  allWordsAreInDictionary = true
  for word in cipherWords
    newWord = String.new
    word.each_byte do |c|
      index = (c+i > 122) ? (c+i-26) : c+i
      newWord << (index).chr
    end
  	if !dictionaryWords.include?(newWord) then
  		allWordsAreInDictionary = false
  		break
    end
  end
  if allWordsAreInDictionary then
  	break
  end
end

puts "value of i: #{i}"