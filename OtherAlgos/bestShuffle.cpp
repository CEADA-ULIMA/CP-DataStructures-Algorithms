#include <bits/stdc++.h>
using namespace std;

string best_shuffle(string word){
    string ans = word;
    shuffle(ans.begin() , ans.end() , default_random_engine() );
    for(int i = 0; i < word.size() ; i++){
        if(ans[i] == word[i]){
            for(int j = 0; j < word.size() ; j++){
                if(ans[i] != ans[j] && word[i] != ans[j] && word[j] != ans[i]){
                    swap(ans[i] , ans[j]);
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    string word = "tree";
    string ans = best_shuffle(word);
    cout << ans << endl;
    return 0;
}