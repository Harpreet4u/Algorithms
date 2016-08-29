// O(keylength) retrieval
// O(alphabets(26) * key_length * no_of_keys) space complexity
//
// Faster than BST O(Mlog(N)) M-max_key_length N-no_of_keys
// BST O(N) N-no_of_keys space complexity better than trie
// bad in space complexity
// see compressed tries for better space complexities.
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define INDEX(x) ((int)x - (int)'a')
#define ALPHABET_SIZE (26)
#define FREE(p) \
    free(p); \
    p = NULL;

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

typedef struct trie_node trie_node_t;

struct trie_node {
    trie_node_t *children[ALPHABET_SIZE];
    int value;
};

typedef struct trie trie_t;
struct trie {
    trie_node_t *root;
    int count;
};

trie_node_t *getNode() {
    
    trie_node_t *tmp;
    tmp = (trie_node_t *)malloc(sizeof(trie_node_t));

    if(tmp) {
        tmp->value = 0;
        for(int i=0;i<ALPHABET_SIZE;i++) {
            tmp->children[i] = NULL;
        }
    }
    return tmp;
}   

void init(trie_t *pTrie) {
    pTrie->root = getNode();
    pTrie->count = 0;
}

void insert(trie_t *pTrie, const char *key) {

    int index;
    int keylength = strlen(key);
    trie_node_t *pNode = pTrie->root;

    pTrie->count++;
    for (int level=0;level<keylength;level++) {
        index = INDEX(key[level]);
        if (!pNode->children[index]) {
            pNode->children[index] = getNode();
        }
        pNode = pNode->children[index];
    }
    pNode->value = pTrie->count;
}

bool search(trie_t *pTrie, const char *key) {

    int index;
    int keylength = strlen(key);
    trie_node_t *pNode = pTrie->root;

    for (int level=0;level<keylength;level++) {
        index = INDEX(key[level]);
        if(!pNode->children[index]) {
            return false;
        }
    }
    return (pNode && pNode->value);
}

bool isFreeNode(trie_node_t *pNode) {
    for (int i=0;i<ALPHABET_SIZE;i++) {
        if (pNode->children[i]) {
            return false;
        }
    }
    return true;
}

bool isLeafNode(trie_node_t *pNode) {
    return pNode->value != 0;
}

bool deleteHelper(trie_node_t *pNode, const char *key, int level, int len) {
    if (pNode) {
        if (len == level) {
            if (pNode->value) {
                pNode->value = 0;
                if (isFreeNode(pNode)) {
                    return true;
                }
                return false;
            }
        } else {
            int index = INDEX(key[level]);
            if (deleteHelper(pNode->children[index], key, level+1, len)) {
                FREE(pNode->children[index]);
            }
            return (!isLeafNode(pNode) && isFreeNode(pNode));
        }

    }
    return false;
}

void deleteNode(trie_t *pTrie, const char *key) {
    int keylength = strlen(key);

    if (keylength > 0) {
        deleteHelper(pTrie->root, key, 0, keylength);
    }
}

int main()
{
    char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    trie_t trie;
    init(&trie);
    
    for(int i = 0; i < ARRAY_SIZE(keys); i++) {
      insert(&trie, keys[i]);
    }
    deleteNode(&trie, keys[0]);
    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");
    
    return 0;
}
