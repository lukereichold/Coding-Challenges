#!/usr/bin/env python3
# text_munger.py: Scramble ("munge") the centers of each word in a given text file.
# Problem Definition: http://rubyquiz.com/quiz76.html
# Usage: python text_munger.py [filename.in]
# Author: Luke Reichold

import unittest, re
from sys import argv, exit
from random import sample

class String:

    def __init__(self, text):
        self.__text = text

    def __replace_curly_quotes(self):
        clean = self.__text.replace('“', '"').replace('”', '"')
        clean = clean.replace('‘', "'").replace("’", "'")
        return clean

    def __parse_tokens(self, tokens):
        return [Word(token).scramble() for token in tokens]

    def munge(self):
        clean = self.__replace_curly_quotes()
        tokens = re.findall(r"[(\w|')+$]+|[ \"\(\).,!?;]", clean)
        munged = ('').join(self.__parse_tokens(tokens))
        return munged

class Word:
    def __init__(self, word):
        self.__word = word

    def __calculate_range_to_shuffle(self, word):
        ''' To shuffle all but first and last LETTERS, 
            account for condition where first/last chars are quotes. 
            Could be adjusted if we'd like to handle contractions differently. '''
        start_delta = 2 if word.startswith("'") else 1
        end_delta = -2 if word.endswith("'") else -1
        return [start_delta, end_delta]

    def __get_middle(self):
        start, end = self.__calculate_range_to_shuffle(self.__word)
        return self.__word[start:end]

    def __get_shuffled_middle(self):
        return ''.join(sample(self.__get_middle(), len(self.__get_middle())))

    def __should_stop_shuffling(self, shuffled_word):
        return self.__word != shuffled_word

    def can_be_scrambled(self):
        return self.__get_middle() != len(self.__get_middle()) * self.__get_middle()[0]

    def scramble(self):
        w = self.__word
        if len(w) > 3 and self.can_be_scrambled():
            start, end = self.__calculate_range_to_shuffle(self.__word)
            while True:
                w = w[:start] + self.__get_shuffled_middle() + w[end:]
                if self.__should_stop_shuffling(w):
                    break;
        self.__word = w
        return w

def main():
    if len(argv) != 2:
        exit('Usage: python text_munger.py [filename.in]')
    with open(argv[1]) as file:
        print(String(file.read()).munge())


# Unit Tests
class Munging_Foreign_Characters_Tests(unittest.TestCase):

    def setUp(self):
        self.original = "Sì, vorrei un caffè per favore."  # add some more foreign characters?
        self.munged = String(self.original).munge()

    def test_FirstAndLastCharactersUnchanged(self):
        before = self.original.split()[3]
        after  = self.munged.split()[3]

        self.assertEqual(before[0], after[0], "first characters should not change")
        self.assertEqual(before[len(before)-1], after[len(after)-1], "last characters should not change")

class Munging_Sentences_With_Heavy_Punctuation_Tests(unittest.TestCase):

    def setUp(self):
        self.original = "The Jones' want to know, \"Are you hungry?\" ..... Also, what are you talkin' 'bout?!"
        self.munged = String(self.original).munge()

    def test_WordsWithEndingApostrope_EndWithApostropheWhenShuffled(self):
        talkin = self.munged.split()[-2]
        self.assertTrue(talkin.endswith("'"))

    def test_WordsWithStartingApostrope_StartWithApostropheWhenShuffled(self):
        bout = self.munged.split()[-1]
        self.assertTrue(bout.startswith("'"))

    def test_SentencesWithQuotes_RetainQuotesInProperIndices(self):
        idx_first_quote_orig  = self.original.index('"')
        idx_second_quote_orig = self.original[idx_first_quote_orig+1:].index('"') + (idx_first_quote_orig + 1)

        idx_first_quote_munged  = self.munged.index('"')
        idx_second_quote_munged = self.munged[idx_first_quote_munged+1:].index('"') + (idx_first_quote_munged + 1)

        self.assertEqual(idx_first_quote_orig, idx_first_quote_munged, "positions of first quote character should not change")
        self.assertEqual(idx_second_quote_orig, idx_second_quote_munged, "positions of second quote character should not change")

class Munging_Sentences_With_High_Word_Count_Tests(unittest.TestCase):

    def setUp(self):
        self.original = "There’s something about love that builds up and is creative. And there is a power there that eventually transforms individuals. Just keep being friendly to that person. Just keep loving them, and they can’t stand it too long. They react with guilt feelings, and sometimes they’ll hate you a little more at that transition period, but just keep loving them."
        self.munged = String(self.original).munge()

    def test_MungedSentence_RetainsSameTotalCharacterCount(self):
        self.assertEqual(len(self.original), len(self.munged), "length of munged sentence should be same as length of original")

    def test_MungedSentence_RetainsSameWordCount(self):
        self.assertEqual(len(self.original.split()), len(self.munged.split()), "munged sentence should retain word count of original")

    def test_WordsWithLessThanFourCharacters_RemainUnshuffled(self):
        for idx, word in enumerate(self.munged.split()):
            if len(word) < 4:
                self.assertEqual(word, self.original.split()[idx], "words less than 4 characters should remain unshuffled")

    def test_WordsWithFourOrMoreCharacters_AreShuffled(self):
        for idx, word in enumerate(self.munged.split()):
            if len(word) >= 4 and Word(word).can_be_scrambled():
                self.assertNotEqual(word, self.original.split()[idx], "words with 4 or more characters should be shuffled")

if __name__ == "__main__":
    main()
    # unittest.main() # comment main() & execute this for unit tests
