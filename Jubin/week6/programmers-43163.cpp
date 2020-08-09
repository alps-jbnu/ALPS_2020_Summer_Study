#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

bool IsConnectable(const char* s1, const char* s2)
{
    int count = 0;
    
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            ++count;
        }
        ++s1;
        ++s2;
    }    
    
    return count == 1;
}

int dfs(int depth, const string& cur, const string& target, unordered_map<string, vector<string>>& adj, unordered_map<string, bool>& visited)
{
    visited[cur] = true;
    
    if (cur == target)
    {
        return depth;
    }
        
    for (auto& next : adj[cur])
    {
        if (!visited[next])
        {
            return dfs(depth + 1, next, target, adj, visited);
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;
    
    bool hasTarget = false;
    for (const string& word : words)
    {
        if (target == word)
        {
            hasTarget = true;
            break;
        }
    }
    
    if (!hasTarget)
    {
        return 0;
    }
    
    for (const string& word : words)
    {
        if (IsConnectable(begin.c_str(), word.c_str()))
        {
            adj[word].push_back(begin);
            adj[begin].push_back(word);
        }

        if (IsConnectable(target.c_str(), word.c_str()))
        {
            adj[word].push_back(target);
            adj[target].push_back(word);
        }

        for (const string& anotherWord : words)
        {
            if (word.c_str() == anotherWord.c_str())
            {
                continue;
            }
            
            if (IsConnectable(anotherWord.c_str(), word.c_str()))
            {
                adj[word].push_back(anotherWord);
                adj[anotherWord].push_back(word);
            }
        }
    }
        
    return dfs(0, begin, target, adj, visited);
}
