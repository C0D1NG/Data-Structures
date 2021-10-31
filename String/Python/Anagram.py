def anagrams(string1, string2):
    myList1 = list(string1)
    myList1.sort()
    sortedString1 = "".join(myList1)

    myList2 = list(string2)
    myList2.sort()
    sortedString2 = "".join(myList2)

    return sortedString1 == sortedString2


def create_key(word):
    letters = []
    for c in word:
        letters.append(c.lower())
    letters = sorted(letters)
    return ''.join(letters)


def build_dictionary():
    words_list = []
    anagramsDictionary = {}
    raw_word_list = open('wordList.txt', 'r')
    for line in raw_word_list.readlines():
        word = line.strip()
        if word.startswith("v"):
            words_list.append(word)
    raw_word_list.close()
    for word in words_list:
        key = create_key(word)
        if key not in anagramsDictionary:
            anagramsDictionary[key] = ''
        anagramsDictionary[key] = word
    return anagramsDictionary

