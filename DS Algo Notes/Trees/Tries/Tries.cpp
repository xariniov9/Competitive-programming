#include<bits/stdc++.h>

using namespace std;

struct trieNode{
    struct trieNode * next[27];
    trieNode(){
        for(int i=0; i<=26; i++)
            next[i] = NULL;
    }
};

 // next[26] be special character $

void insertToTrie(struct trieNode * root, char * str){
    if(str[0] == '\0'){
        if(root->next[26] == NULL){
            root->next[26] = new trieNode();
        }
        return;
    }
    if(root->next[str[0] - 'a'] != NULL){
        insertToTrie(root->next[str[0] - 'a'], str+1);
        return;
    }
    root->next[str[0] - 'a'] = new trieNode();
    insertToTrie(root->next[str[0] - 'a'], str+1);

}

void printTrieDfs(struct trieNode * root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<26; i++){
        if(root->next[i] != NULL){
            printf("%c",i + 'a');
            printTrieDfs(root->next[i]);
        }
    }
}

int main(){
    char str[] = "helloworld";

    struct trieNode root;
    insertToTrie(&root, str);

    printTrieDfs(&root);
    printf("\n");
    return 0;
}
