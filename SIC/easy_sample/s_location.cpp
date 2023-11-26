#include <bits/stdc++.h>
using namespace std;

int main(){
    string sentence = "Hi i am a teacher 2 123 123 456 789";

    size_t pos = 0;

    while ((pos = sentence.find(' ', pos)) != string::npos) {
        // 印出空格之前的子串
        cout << sentence.substr(pos + 1, sentence.find(' ', pos + 1) - pos - 1) << endl;
        pos++;
    }

    if (pos < sentence.size()) {
        cout << sentence.substr(pos) <<"123"<< endl;
    }
}