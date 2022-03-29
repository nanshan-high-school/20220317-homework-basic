#include "ConsoleColorFormat.h"
#include <ctime>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Answer {
public:
  int value;
  int min, max;
  bool guess(int _guess) {
    if (_guess > max || _guess < min) {
      return false;
    } else if (_guess > value) {
      max = _guess;
    } else if (_guess < value) {
      min = _guess;
    }
    return true;
  }
};

int randomInt(int, int);
void SinglePlayer(Answer);
void PlayWithComputer(Answer);
void LetComputerGuess(Answer);

int main() {
  srand(time(NULL));

  while (true) {
    int option;
    cout << FG_MAGENTA;
    cout << "Mode?" << "\n";
    cout << "1: Single Player" << "\n";
    cout << "2: Play with computer" << "\n";
    cout << "3: Let computer guess" << "\n";
    cout << RESET_COLOR;

    Answer answer;
    answer.min = 0;
    answer.max = 100;
    answer.value = -1;

    cin >> option;
    if (option == 1) {
      SinglePlayer(answer);
    } else if (option == 2) {
      PlayWithComputer(answer);
    } else if (option == 3) {
      LetComputerGuess(answer);
    } else {
      cout << FG_RED << "Please choose a correct statement" << "\n" << RESET_COLOR;
    }
  }
}

int randomInt(int max, int min) { return rand() % (max - min + 1) + min; }

void SinglePlayer(Answer answer) {
  answer.value = randomInt(100, 0);
  while (true) {
    int guess = 0;
    cout << FG_GREEN << "Guess?(" << answer.min << "~" << answer.max << ")\n" << RESET_COLOR;
    cin >> guess;
    if (guess == answer.value) {
      cout << FG_YELLOW << "You guessed the correct number! woah!\n" << RESET_COLOR;
      return;
    }

    if (!answer.guess(guess)) {
      cout << FG_RED << "Range is between " << answer.min << "~" << answer.max << "\n" << RESET_COLOR;
    }
  }
}

void PlayWithComputer(Answer answer) {
  int turn = randomInt(1, 0);
  answer.value = randomInt(100, 0);
  if (turn) {
    cout << FG_MAGENTA << "You guess first\n" << RESET_COLOR;
  } else {
    cout << FG_MAGENTA << "Computer guess first\n" << RESET_COLOR;
  }

  while (true) {
    if (turn) {
      int guess;
      cout << FG_GREEN << "Guess?(" << answer.min << "~" << answer.max << ")\n" << RESET_COLOR;
      cin >> guess;
      if (guess == answer.value) {
        cout << FG_YELLOW << "You guessed the correct number! woah!\n" << RESET_COLOR;
        return;
      }

      if (!answer.guess(guess)) {
        cout << FG_RED << "Range is between " << answer.min << "~" << answer.max << "\n" << RESET_COLOR;
      }
      turn--;
    } else {
      int computerGuess;
      computerGuess = randomInt(answer.max - 1, answer.min + 1);
      cout << BG_CYAN << "Computer:" << computerGuess << "\n" << RESET_COLOR;
      if (computerGuess == answer.value) {
        cout << FG_YELLOW << "Computer guessed the correct number! woah!\n" << RESET_COLOR;
        return;
      }

      answer.guess(computerGuess);
      turn++;
    }
  }
}

void LetComputerGuess(Answer answer) {
  cout << FG_MAGENTA << "Minimum number?" << "\n" << RESET_COLOR;
  cin >> answer.min;
  cout << FG_MAGENTA << "Maximum number?" << "\n" << RESET_COLOR;
  cin >> answer.max;
  answer.value = randomInt(answer.max, answer.min);

  while (true) {
    int computerGuess = randomInt(answer.max - 1, answer.min + 1);
    cout << "Range:" << answer.min << "~" << answer.max << "\n" << RESET_COLOR;
    cout << BG_CYAN << "Computer:" << computerGuess << "\n" << RESET_COLOR;
    if (computerGuess == answer.value) {
      cout << FG_YELLOW << "Computer guessed the correct number! woah!\n" << RESET_COLOR;
      return;
    }

    answer.guess(computerGuess);
  }
}
// 笑死 好醜

// We're no strangers to love
// You know the rules and so do I
// A full commitment's what I'm thinking of
// You wouldn't get this from any other guy
// I just wanna tell you how I'm feeling
// Gotta make you understand
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
// Never gonna tell a lie and hurt you
// We've known each other for so long
// Your heart's been aching but you're too shy to say it
// Inside we both know what's been going on
// We know the game and we're gonna play it
// And if you ask me how I'm feeling
// Don't tell me you're too blind to see
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
// Never gonna tell a lie and hurt you
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
// Never gonna tell a lie and hurt you
// Never gonna give, never gonna give
// (Give you up)
// We've known each other for so long
// Your heart's been aching but you're too shy to say it
// Inside we both know what's been going on
// We know the game and we're gonna play it
// I just wanna tell you how I'm feeling
// Gotta make you understand
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
// Never gonna tell a lie and hurt you
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
// Never gonna tell a lie and hurt you
// Never gonna give you up
// Never gonna let you down
// Never gonna run around and desert you
// Never gonna make you cry
// Never gonna say goodbye
