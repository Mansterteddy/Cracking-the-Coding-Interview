#define MAX 26

typedef struct Trie
{
	Trie *next[Max];
	int v;
};

Trie *root;

