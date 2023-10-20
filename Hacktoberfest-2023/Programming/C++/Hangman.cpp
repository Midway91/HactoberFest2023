
#include<bits/stdc++.h>
std::string get_random_word(std::vector<std::string>& words);
void play();
std::vector<std::string> words = {"programming", "hangman", "games"};
std::string hangman_art[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

int main()
{
    srand(time(0));
    std::cout << "Welcome to Hangman!\n";
    play();

    return 0;
}

void play()
{
    std::string secret_word = get_random_word(words);
    std::string guess_word = secret_word;
    for (int i = 0; i < secret_word.length(); ++i)
    {
        guess_word[i] = '_';
    }
    int try_no = 0;
    char guess;

    while (true)
    {
        std::cout << hangman_art[try_no] << "\n";
        std::cout << guess_word << "\n";
        std::cout << "Enter your guess:\n";
        std::cin >> guess;

        if (secret_word.find(guess) != std::string::npos)
            {   
                for (int i = 0; i < guess_word.length(); ++i)
                {
                    if (secret_word[i] == guess)
                    {
                        guess_word[i] = guess;
                    }
                }
            if (secret_word == guess_word)
            {
                std::cout << hangman_art[try_no] << "\n";
                std::cout << guess_word << "\n";
                std::cout << "You win! The word was " << secret_word << "\n";
                break;
            }
        } else {
            ++try_no;
        }
        if (try_no >= 6)
        {
            std::cout << hangman_art[try_no] << "\n";
            std::cout << guess_word << "\n";
            std::cout << "You lost! The word was " << secret_word << "\n";
            break;
        }
    }
}

std::string get_random_word(std::vector<std::string>& words)
{
    return words[rand() % words.size()];
}
