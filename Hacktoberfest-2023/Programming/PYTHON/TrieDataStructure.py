class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with_prefix(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

    def delete(self, word):
        def _delete_helper(node, word, depth):
            if depth == len(word):
                node.is_end_of_word = False
                return not node.children

            char = word[depth]
            if char in node.children and _delete_helper(
                node.children[char], word, depth + 1
            ):
                del node.children[char]
                return not node.children

            return False


if __name__ == "__main__":
    trie = Trie()

    while True:
        print("\nOperations:")
        print("1. Insert")
        print("2. Search")
        print("3. Check Prefix")
        print("4. Delete")
        print("5. Exit")

        choice = int(input("Enter your choice (1-5): "))

        if choice == 1:
            word = input("Enter the word to insert: ")
            trie.insert(word)
            print(f'"{word}" inserted into the trie.')

        elif choice == 2:
            word = input("Enter the word to search: ")
            if trie.search(word):
                print(f'"{word}" found in the trie.')
            else:
                print(f'"{word}" not found in the trie.')

        elif choice == 3:
            prefix = input("Enter the prefix to check: ")
            if trie.starts_with_prefix(prefix):
                print(f'Trie contains words with prefix "{prefix}".')
            else:
                print(f'No words found with prefix "{prefix}".')

        elif choice == 4:
            word = input("Enter the word to delete: ")
            trie.delete(word)
            print(f'"{word}" deleted from the trie.')

        elif choice == 5:
            break

        else:
            print("Invalid choice. Please choose a number from 1 to 5.")
