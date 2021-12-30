#include <string>
#include <unordered_set>

using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_set<string> uniqueUnseenWords;
    unordered_set<string> repeatedUnseenWords;
    for (const string& word : words2)
    {   
        if (repeatedUnseenWords.find(word) == repeatedUnseenWords.end())
        {
            if (uniqueUnseenWords.find(word) == uniqueUnseenWords.end())
            {
                uniqueUnseenWords.insert(word);
            }
            else
            {
                repeatedUnseenWords.insert(word);
            }
        }
    }

    int count = 0;
    unordered_set<string> uniqueWords;
    unordered_set<string> repeatedWords;
    for (const string& word : words1)
    {
        if (repeatedUnseenWords.find(word) == repeatedUnseenWords.end() && uniqueUnseenWords.find(word) != uniqueUnseenWords.end())
        {
            if (uniqueWords.find(word) == uniqueWords.end())
            {
                ++count;
                uniqueWords.insert(word);
            }
            else 
            {
                if (repeatedWords.find(word) == repeatedWords.end())
                {
                    --count;
                    repeatedWords.insert(word);
                }
            }
        }
    }

    return count;
};
