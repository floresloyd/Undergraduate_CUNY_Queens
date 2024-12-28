class MyTrieTest {
	public static void main(String[] args){
		MyTrie trie = new MyTrie();

		trie.add("apple"); 
		System.out.println("Added 'apple' to the trie\n");

		boolean ret = trie.find("apple");   // returns true
		System.out.println("Searching for apple: " + ret);

		ret = trie.find("app");     // returns false
		System.out.println("Searching for app: " + ret);

		ret = trie.startsWith("app"); // returns true
		System.out.println("startsWith app: " + ret);

		trie.add("app");
		System.out.println("Added 'app' to the trie\n");

		trie.find("app");     // returns true
		System.out.println("Searching for app: " + ret);
	} // end-main
}
