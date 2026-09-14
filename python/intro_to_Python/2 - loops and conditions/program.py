if __name__ == "__main__":
    # for loop
    sum = 0

    for i in range(10, 101, 5):  # don't need parenthesis around condition
        sum += i

    print(f"10 + 15 + 20 + ... + 100 = {sum}")

    # while loop; lets find the first capital letter
    word = "abcEFgHIj"
    i = 0
    while (i < len(word)) and not word[i].isupper():
        i += 1  # no i++ in Python

    if i != len(word):  # Python doesn't null-terminate strings, so we do this
        print(f"the first capital letter of \"{word}\" is '{word[i]}'.")
    else:
        print(f"{word} contains no capital letters.")

    # if, else if, else
    choice = 'b'  # NOTE: Python doesn't care if you use single/double quotes!

    if choice == 'a':
        print("choice 1")
    elif choice == 'b':  # NOTE: Python uses `elif`, not `else if`
        print("choice 2")
    else:
        print("other choice")
