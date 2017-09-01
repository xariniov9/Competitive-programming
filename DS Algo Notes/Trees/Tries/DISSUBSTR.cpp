
// problem link : http://www.spoj.com/problems/DISUBSTR/

// trie do not work!

// himanshu tiwari


#include<cstdio>
#include<cstring>


using namespace std;

struct trieNode{
    struct trieNode * next[257];
    trieNode(){
        for(int i=0; i<=256; i++)
            next[i] = NULL;
    }
};

 // next[26] be special character $

void insertToTrie(struct trieNode * root, char * str){
    if(str[0] == '\0'){
        if(root->next[256] == NULL){
            root->next[256] = new trieNode();
        }
        return;
    }
    if(root->next[str[0]] != NULL){
        insertToTrie(root->next[str[0]], str+1);
        return;
    }
    root->next[str[0]] = new trieNode();
    insertToTrie(root->next[str[0]], str+1);

}

int countNodes(struct trieNode * root){
    if(root == NULL)
        return 0;
    int ans = 0;
    for(int i=0; i<256; i++){
        if(root->next[i] != NULL)
            ans += countNodes(root->next[i]);
    }
    return ans + 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char str[1005];
        scanf("%s",str);
        int l = strlen(str);
        struct trieNode root;
        for(int i=0; i<l; i++){
            insertToTrie(&root, str+i);
        }
        int ans = countNodes(&root);
        printf("%d\n",ans-1);
    }
    return 0;
}
