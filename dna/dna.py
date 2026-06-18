import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    filename = sys.argv[1]
    with open(filename) as f:
        reader = csv.DictReader(f)
        for i in reader:
            database.append(i)

    # TODO: Read DNA sequence file into a variable
    # create string and populate it with the first line of the 3rd argument
    with open(sys.argv[2]) as dna_file:
        dna_sequence = dna_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Iterate through each row in the database
    # For each row (dictionary) you're going to iterate through each key
    # The first key is going name and then store that in a variable
    # The remainding keys are the str's
    # Evaluate each STR against the long string using longest_match
        player = []
    subsequences = list(database[0].keys())[1:]
    for i in subseque




    nces:
        player.append(longest_match(dna_sequence, i))

    # # TODO: Check database for matching profiles
    for person in database:
        name = person['name']
        matches = 0

        index = 0  # Index variable to access the corresponding index of `player`
        for subsequence in subsequences:
            if int(person[subsequence]) == player[index]:
                matches += 1
            index += 1

        if matches == len(subsequences):
            print(name)
            return
    print("No match")
    return


# This returns back the number of dna subsequences. For example for AGAT if it continously has AGAT 16 times it will return 16
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
