# 🎮 Guess the Word Game (C Language)
📌 Overview
This is a simple command-line based **Word Guessing Game** written in C.
The program randomly selects a meaningful 5-letter word and allows the user to guess it letter by letter within a limited number of attempts.

## 🚀 Features

* 🎯 Random selection of meaningful words
* 🔁 No repetition of words during gameplay
* 🔤 Case-insensitive input handling
* ⚠️ Input validation (only alphabets allowed)
* 🔄 Multiple rounds support
* 🎮 User-friendly console interaction

---

## 🛠️ Technologies Used

* C Programming Language
* Standard Libraries:

  * `stdio.h`
  * `string.h`
  * `ctype.h`
  * `stdlib.h`
  * `time.h`

---

## ▶️ How to Run

### Step 1: Compile the program

```bash
gcc program.c -o game
```

### Step 2: Run the program

```bash
./game
```

---

## 🎯 How to Play

1. The program selects a random **5-letter word**.
2. The word is displayed as underscores (`_ _ _ _ _`).
3. You need to guess one letter at a time.
4. If the letter is correct:

   * It is revealed in the word.
5. If the letter is wrong:

   * Attempts decrease.
6. You have **10 attempts** to guess the word.
7. The game ends when:

   * You guess the word correctly 🎉
   * OR you run out of attempts 💀

---

## 🔄 Game Flow

* After each round, the player is asked:

  ```
  Play next word? (y/n)
  ```
* The game continues until:

  * The player chooses to stop
  * OR all words are used

---

## ⚠️ Rules & Constraints

* Only alphabet characters are allowed as input
* Repeated guesses are not counted
* Each word is used **only once**
* Maximum words available: 30

---

## 📂 Code Structure

* **Word Selection:** Random using `rand()`
* **Tracking Used Words:** `used[]` array
* **Game Logic:** Loop-based guessing system
* **Validation:** `isalpha()` and `toupper()`

---

## 💡 Future Enhancements

* 🎨 Add ASCII-based Hangman visuals
* 📊 Score tracking system
* 📚 Load words from external file
* ⏱ Add timer-based challenges
* 🎮 Difficulty levels (easy/medium/hard)

---

## 👩‍💻 Author

Developed as a practice project to understand:

* Arrays
* Strings
* Random number generation
* Game logic in C

---

## 📜 License

This project is open-source and free to use for learning purposes.

---
