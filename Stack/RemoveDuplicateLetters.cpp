#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string removeDuplicateLetters(string s)
{
    string ans;
    int count[26] = {0};
    int visited[26] = {0};

    for(char ch : s)
    {
        count[ch-'a']++;
    }
    for(char ch : s)
    {
        if(!visited[ch-'a'])
        {
            count[ch-'a']--;

            while(ans.size()>0 && ans.back()>ch && count[ans.back()-'a']>0)
            {
                visited[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            visited[ch-'a'] = 1;
            ans.push_back(ch);
        }
    }
}
int main()
{
return 0;
}