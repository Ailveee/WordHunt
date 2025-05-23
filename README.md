# WordHunt 🎯

**WordHunt** is a C-based word-guessing game inspired by the popular game Wordle. This prototype allows players to guess words from various themed lists, offering multiple difficulty levels for an engaging and educational experience.

---

## 🔍 Features

- 🎮 Command-line interface for quick and lightweight gameplay
- 🧠 Three difficulty levels: Easy, Medium, and Hard
- 🌍 Themed word lists:
  - Nature
  - Profession
  - Fantasy
- 📦 Simple and minimal dependencies (just a C compiler)

---

## 📁 Project Structure

```
WordHunt/
├── Wordhunt.c                # Main source code file
├── easy_Nature.txt          # Word list for Easy level - Nature theme
├── medium_Profession.txt    # Word list for Medium level - Profession theme
├── hard_Fantasy.txt         # Word list for Hard level - Fantasy theme
└── README.md                # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (GCC recommended)

### Compilation

```bash
gcc -o wordhunt Wordhunt.c
```

### Run the Game

```bash
./wordhunt
```

Follow the prompts to select a difficulty and start guessing the word!

---

## 🔧 How It Works

1. Choose a difficulty level.
2. The program randomly selects a word from the corresponding word list.
3. You have a limited number of tries to guess the word.
4. After each guess, feedback is provided to guide you.

---

## 📌 TODO / Future Improvements

- Add color-coded feedback (like Wordle)
- Implement a graphical user interface (GUI)
- Add a scoring system
- Support saving high scores or player profiles

---

## 🤝 Contributing

Contributions are welcome! Feel free to fork the repository, make changes, and submit a pull request.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🙌 Acknowledgments

Inspired by the classic word-guessing games and puzzles. Created for learning and fun!
