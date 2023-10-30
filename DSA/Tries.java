import java.util.*;

class Tries {

    String meaning;
    boolean isWord;
    char c;
    Tries[] tries;

    public Tries(char c) {
        this.c = c;
        tries = new Tries[26];
        isWord = false;
        meaning = null;
    }

    public void add(String word, String meaning) {
        if(word.isEmpty()) {
            this.isWord = true;
            this.meaning = meaning;
            return;
        }

        char letter = word.charAt(0);
        int index = letter - 'a';

        if(this.tries[index] = null)
            this.tries[index] = new Tries(letter);

        this.tries[index].add(word.substring(1), meaning);
    }

    public boolean search(String word) {
        if(word.isEmpty())
            return this.isWord;

        char letter = word.charAt(0);
        int index = letter - 'a';
        if(this.tries[index] == null)
            return false;

        return this.tries[index].search(word.substring(1));
    }

    public String meaning(String word) {
        if(word.isEmpty())
            return this.meaning;

        char letter = word.charAt(0);
        int index = letter - 'a';
        if(this.tries[index] == null)
            return "Word doesn't exist in the dictionary";

        return this.tries[index].meaning(word.substring(1));
    }
}