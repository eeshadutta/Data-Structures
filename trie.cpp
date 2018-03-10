#include <bits/stdc++.h>
using namespace std;

typedef struct trie {
    trie * child[26];
    char ch;
    int freq; //no of strings which end here
}trie;

trie * createNode(char c){
    trie * node;
    node = (trie*)malloc(sizeof(trie));
    node->ch = c;
    for (int i=0; i<26; i++){
        node->child[i] = NULL;
    }
    node->freq = 0;
    return node;
}

void insert(trie * root, string str){
    trie * node = root;
    int ind;
    for (int i=0; i<str.size(); i++){
        ind = str[i] - 'a';
        if (node->child[ind] == NULL){
            node->child[ind] = createNode(str[i]);
        }
        node = node->child[ind];
    }
    node->freq++;
    return;
}

bool search(trie * root, string str){
    trie * node = root;
    int ind;
    for (int i=0; i<str.size(); i++){
        ind = str[i] - 'a';
        if (node->child[ind] == NULL){
            return false;
        }
        node = node->child[ind];
    }
    if (node->freq > 0){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    trie * root;
    root = createNode('\0');
    int flag;
    printf("0)Exit 1)Insert 2)Search\n");
    scanf("%d", &flag);
    while (flag)
    {
        if (flag == 1)
        {
            string str;
            cin>>str;
            insert(root, str);
        }
        else if (flag == 2)
        {
            string str;
            cin>>str;
            bool val = search(root, str);
            if (val == true){
                printf("exists\n");
            }
            else {
                printf("doesn't exist\n");
            }
        }
        printf("0)Exit 1)Insert 2)Search\n");
        scanf("%d", &flag);
    }
    return 0;
}