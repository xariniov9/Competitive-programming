#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    node * ch[27];
    int type;
    int leaf;
} Node;

/*
    0 all unblocked
    1 all bloked
    2 few of both
*/

Node * newNode(){
    Node * nd = (Node *)malloc(sizeof(Node));
    for(int i=0; i<27; i++)
        nd->ch[i] = NULL;
    nd->type = 0;
    nd->leaf = 0;
    return nd;
}


char * res[200006];
int itr = 0, pos=1;

void Insert(Node * head, char * str, int type){
    if(str[0] == '\0'){
        return;
    }

    if(head->ch[str[0] - 'a'] == NULL){
        head->ch[str[0] - 'a'] = newNode();
        if(type == '-'){
            head->ch[str[0] - 'a']->type = 1;
        }
        if(str[1] < 'a' || str[1] > 'z'){
            head->ch[str[0] - 'a']->leaf = 1;
        }
        Insert(head->ch[str[0] - 'a'], str+1, type);
    } else {
        if(str[1] < 'a' || str[1] > 'z'){
            head->ch[str[0] - 'a']->leaf = 1;
        }
        if(type == '-'){
            if(head->ch[str[0] - 'a']->type == 0)
                head->ch[str[0] - 'a']->type = 2;
        } else {
            if(head->ch[str[0] - 'a']->leaf == 1 && head->ch[str[0] - 'a']->type == 1){
                pos = 0;
                return;
            }
            if(head->ch[str[0] - 'a']->type == 1)
                head->ch[str[0] - 'a']->type = 2;
        }
        Insert(head->ch[str[0] - 'a'], str+1, type);
    }
}


char * Strdup(char * s){
    int n=strlen(s);
    char * ret = (char *)malloc(1 + sizeof(char) * n);
    for(int i=0; i<=n; i++)
        ret[i] = s[i];
    return ret;
}

void Query(Node * head, char * running, int idx){
    if(head == NULL){
        pos = 0;
        return;
    }
    if(head->type == 0)
        return;
    if(head->type == 1){
        res[itr++] = Strdup(running);
        return;
    }
    for(int i=0; i<26; i++){
        if(head->ch[i] != NULL){
            running[idx] = i+'a';
            Query(head->ch[i], running, idx+1);
            running[idx] = '\0';
        }
    }
}

void printTrie(Node * head){
    if(head == NULL){
        printf("\n");
        return;
    }
    for(int i=0; i<26; i++){
        if(head->ch[i] != NULL){
            printf("%c",i+'a');
            printTrie(head->ch[i]);
        }
    }
}

char web[250006];
char type[5];
char run[200006] = {0};
int main(){
    int n, mi=0;
    pos=1;
    scanf("%d",&n);
    Node * head = newNode();
    while(n--){
        scanf("%s %s",type, web);
        if(type[0] == '-')
            mi++;
        Insert(head, web, type[0]);
    }
    head->type = 2;
    //printTrie(head);
    Query(head, run, 0);
    //printf("pos : %d\n",pos);
    if(pos == 0 || (itr == 0 && mi > 0))
        printf("-1\n");
    else{
        printf("%d\n",itr);
        for(int i=0; i<itr; i++)
            printf("%s\n",res[i]);
    }
    return 0;
}
