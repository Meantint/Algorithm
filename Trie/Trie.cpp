#include <cstring>  // memset
#include <iostream>

using namespace std;

const int ALPHA = 26;

int charToNum(char ch) { return ch - 'A'; }

struct Trie {
    Trie* children[ALPHA];  // 각 알파벳을 저장할 수 있는 Trie Pointer를 만든다.

    bool terminal;  // 이 노드에서 종료한다면 true, 아니라면 false
    Trie()          // 생성자
    {
        terminal = false;
        memset(children, 0, sizeof(children));
    }
    ~Trie()  // 소멸자
    {
        for (int i = 0; i < ALPHA; ++i) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    // Trie 구조 안에 문자열을 넣는다.
    void insert(const char* key)
    {
        if (*key == 0) {
            terminal = true;
        }
        else {
            int next = charToNum(*key);

            if (children[next] == NULL) {
                children[next] = new Trie();
            }
            children[next]->insert(key + 1);
        }
    }
    // Trie 구조 안에 원하는 단어가 있는지 찾는다.
    Trie* find(const char* key)
    {
        if (*key == 0) {
            return this;
        }
        int next = charToNum(*key);

        if (children[next] == NULL) {
            return NULL;
        }
        return children[next]->find(key + 1);
    }
};

int main()
{
    Trie* root = new Trie();

    // 대문자만 넣으세요, charToNum Func 설정 때문에
    const char* words[5] = {"APPLE", "BANANA", "APP", "BOW", "BAB"};
    for (int i = 0; i < 5; ++i) {
        root->insert(words[i]);
        // cout << "good " << words[i] << '\n';
    }

    const char* test[6] = {"TEST", "APPP", "BANAN", "APPLE", "ABA", "BAB"};
    int idx = 0;
    while (idx != 6) {
        if (root->find(test[idx]) != 0) {  // 원하는 단어가 있다면
            cout << "I can   find " << test[idx] << '\n';
        }
        else {  // 원하는 단어가 없다면
            cout << "I can't find " << test[idx] << '\n';
        }
        ++idx;
    }

    delete root;

    return 0;
}