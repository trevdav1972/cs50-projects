# TODO
from cs50 import get_string


def main():
    text = get_string("Text: ")
    avel = count_letters(text) / count_words(text)
    avel *= 100
    aves = count_sentences(text) / count_words(text)
    aves *= 100
    index = 0.0588 * avel - 0.296 * aves - 15.8
    index = round(index)
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_words(text):
    counter = 0
    for count in range(len(text)):
        if text[count].isspace():
            counter += 1
    return counter + 1


def count_letters(text):
    counter = 0
    for count in range(len(text)):
        if text[count].isalpha():
            counter += 1
    return counter

def count_sentences(text):
    counter = 0
    for count in range(len(text)):
        if text[count] == '.' or text[count] == '!' or text[count] == '?':
            counter += 1
    return counter


main()

