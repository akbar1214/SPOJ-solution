#include<bits/stdc++.h>

using namespace std;



struct TrieNode {

    TrieNode *children[10];
    bool isEnd = false;
};

TrieNode *getNode() {

    auto *temp = new TrieNode;
    temp->isEnd = false;
    for (int i = 0; i < 10; i++) temp->children[i] = NULL;
    return temp;
}

void insert(TrieNode *head, string key) {

    TrieNode *temp = head;
    int index;
    for (int i = 0; i < key.size(); i++) {

        index = key[i] - '0';
        if (!temp->children[index])
            temp->children[index] = getNode();
        temp = temp->children[index];
    }
    temp->isEnd = true;
}

bool find(TrieNode *head, string key) {

    TrieNode *temp = head;
    int index;
    for (int i = 0; i < key.size(); i++) {

        index = key[i] - '0';
        if (!temp->children[index])
            return false;
        if (temp->children[index]->isEnd)
            return true;

        temp = temp->children[index];
    }
    return temp && !temp->isEnd;
}

int main() {

    int T;
    cin >> T;
    while (T--) {

        TrieNode *head = getNode();
        int n;
        cin >> n;
        bool isConsistent = true;
        set<string> se;
        string nu;
        for (int i = 0; i < n; i++) {
            cin >> nu;
            se.insert(nu);
        }
        for (string number : se) {

            if (find(head, number)) {
                isConsistent = false;
            } else {
                insert(head, number);
            }
        }
        cout << (isConsistent ? "YES\n" : "NO\n");
    }
} 
