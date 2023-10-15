public class Trie {

    private TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode current = root;
        for (char character : word.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                child = new TrieNode();
                current.children.put(character, child);
            }
            current = child;
        }
        current.isWord = true;
    }

    public boolean search(String word) {
        TrieNode current = root;
        for (char character : word.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                return false;
            }
            current = child;
        }
        return current.isWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (char character : prefix.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                return false;
            }
            current = child;
        }
        return true;
    }

    private class TrieNode {

        private char character;
        private HashMap<Character, TrieNode> children;
        private boolean isWord;

        public TrieNode() {
            this.children = new HashMap<>();
            this.isWord = false;
        }
    }
}
