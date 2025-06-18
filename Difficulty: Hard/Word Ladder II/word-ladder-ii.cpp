// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        vector<vector<string>> ans;

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        vector<string> usedOnLevel;
        int level = 0;
 
        
        while(!q.empty()){
            vector<string> front = q.front();
            q.pop();

            if(front.size() > level){
                level += 1;
                
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }
            string word = front.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(front);
                }

                else if(ans[0].size() == front.size()){
                    ans.push_back(front);
                }
            }
            
           

            for(int i=0;i<word.size();i++){
                string newWord = word;

                for(char ch = 'a';ch<= 'z';ch++){
                    newWord[i] = ch;

                    if(st.count(newWord) > 0){
                        front.push_back(newWord);
                        q.push(front);
                        usedOnLevel.push_back(newWord);
                        front.pop_back();
                    }
                }
            }
        }
       return ans;
        
    }
};