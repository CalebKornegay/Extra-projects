from nltk.corpus import words
import random
name = input("Enter your name: ")
word_list = words.words()
ind = random.randint(0, len(word_list))
word = word_list[ind]
word_left = "".ljust(len(word), '_')
chances = 10
guesses = []
while(chances):
    if '_' not in word_left:
        break
    print(f'You have {chances} limbs remaining')
    print(word_left)
    guess = input("Enter a character: ")
    if len(guess) != 1:
        print("Only enter a single character")
        continue
    guess = guess.lower()
    if not guess.isalpha():
        print(f"you did not enter a character [a-z/A-Z], {name} entered {guess}")
        continue
    
    if guess not in guesses:
        guesses.append(guess)
    else:
        print("You already entered that letter, try a different one")
        continue
    
    if guess not in word:
        chances -= 1
    else:
        for i in range(len(word)):
            if guess == word[i]:
                word_left = word_left[:i] + guess + word_left[i+1:]
                
if '_' in word_left:
    print(f"{name} lost, better luck next time, the word was {word}.")
else:
    print(f"Good job, {name} won! The word was {word}.")