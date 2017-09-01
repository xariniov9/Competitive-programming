// problem link : https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2683

// 4682 - XOR Sum

#include<cstdio>

using namespace std;

struct trieNode{
    struct trieNode * left;
    struct trieNode * right;
    trieNode(){
        left = right = NULL;
    }
};

int max(int a, int b){
    return a>b ? a:b;
}
bool Insert(struct trieNode * root, int N){
    for(int i=31; i>=0; i--){
        if(N & (1<<i)){
            if(root->right != NULL){
                root = root->right;
            } else{
                root-> right = new trieNode();
                root = root->right;
            }
        } else {
            if(root->left != NULL){
                root = root->left;
            } else{
                root->left = new trieNode();
                root = root->left;
            }
        }
    }
}

int query(struct trieNode * root, int N){
    int ans = 0;

    for(int i=31; i>=0; i--){
        if(N & (1<<i)){
            if(root->left != NULL){
                ans = ans | (1<<i);
                root = root->left;
            } else{
                root = root->right;
            }
        } else {
            if(root->right != NULL){
                ans = ans | (1<<i);
                root = root->right;
            } else
                root = root->left;
        }
    }
    return ans;
}

int main(){
    int t, x;
    scanf("%d",&t);
    while(t--){
        int ans = -1, runningXOR = 0;
        int n;
        scanf("%d",&n);
        struct trieNode root;
        Insert(&root, 0);
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            runningXOR = runningXOR ^ x;
            Insert(&root, runningXOR);

            ans = max(ans, query(&root, runningXOR));
        }
        printf("%d\n",ans);
    }
    return 0;
}
