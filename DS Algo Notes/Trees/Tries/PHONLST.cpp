
// problem link: http://www.spoj.com/problems/PHONELST/
// HIMANSHU TIWARI

#include<cstdio>
#include<cstring>


using namespace std;

struct trieNode{
    struct trieNode * next[11];
    trieNode(){
        for(int i=0; i<=10; i++)
            next[i] = NULL;
    }
};
bool insertToTrie(struct trieNode * root, char * str){
    if(str[0] == '\0'){
        if(root->next[10] == NULL){
            root->next[10] = new trieNode();
            return true;
        }
        return false;
    }
    if(root->next[10] != NULL)
        return false;
    if(root->next[str[0] - '0'] != NULL){
        if(str[1] == '\0')
            return false;
        return insertToTrie(root->next[str[0] - '0'], str+1);
    }
    root->next[str[0] - '0'] = new trieNode();
    return insertToTrie(root->next[str[0] - '0'], str+1);

}

char str[12];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        struct trieNode root;
        int n;
        bool flag = false;

        scanf("%d",&n);
        while(n--){
            scanf("%s",str);
            str[strlen(str)] = '\0';
            bool ins = insertToTrie(&root, str);
            if(!ins){
                //printf("NO\n");
                flag = true;
                //break;
            }
        }
        if(!flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

