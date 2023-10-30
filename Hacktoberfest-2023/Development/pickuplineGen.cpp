#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<std::string> pickupLines = {
    "Are you a magician? Because whenever I look at you, everyone else disappears.",
    "Do you have a map? I keep getting lost in your eyes.",
    "Is your name Wi-Fi? Because I'm really feeling a connection.",
    "Do you believe in love at first sight, or should I walk by again?",
    "Can I follow you home? Because my parents always told me to follow my dreams.",
    "Do you have a name, or can I call you mine?",
    "Are you made of copper and tellurium? Because you're Cu-Te.",
    "If you were a vegetable, you'd be a cute-cumber!",
    "Are you a campfire? Because you're hot and I want s'more.",
    "Do you have a name, or can I call you mine?",
    "Are you a parking ticket? Because you have 'fine' written all over you.",
    "Is your name Google? Because you have everything I've been searching for.",
    "Are you an interior decorator? When I saw you, the entire room became beautiful.",
    "If you were a fruit, you'd be a fine-apple.",
    "Do you have a pencil? Because I want to erase your past and write our future.",
    "Are you a time traveler? Because I can see you in my future.",
    "Is there an airport nearby, or is that just my heart taking off?",
    "If you were a cat, you'd purr-fect.",
    "Are you a bank loan? Because you have my interest.",
    "Do you have a mirror in your pocket? Because I can see myself in your pants.",
    "Is your name Cinderella? Because your smile is a fairytale.",
    "If you were a vegetable, you'd be a cute-cumber!",
    "Do you have a name, or can I call you mine?",
    "Are you a campfire? Because you're hot and I want s'more.",
    "Do you have a Band-Aid? Because I just scraped my knee falling for you.",
    "Is your name Wi-Fi? Because I'm feeling a connection.",
    "Do you believe in love at first sight, or should I walk by again?",
    "Do you have a map? I just got lost in your eyes.",
    "If you were a fruit, you'd be a fine-apple.",
    "Are you a parking ticket? Because you've got 'fine' written all over you.",
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 

    std::cout << "Random Pickup Line: " << pickupLines[std::rand() % pickupLines.size()] << std::endl;

    return 0;
}
