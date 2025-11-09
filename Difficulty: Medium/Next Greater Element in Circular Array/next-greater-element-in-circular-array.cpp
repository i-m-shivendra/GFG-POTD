class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
          int n = arr.size();
          deque<int> q;
          stack<int> st;
          vector<int> v;
          v.push_back(-1);
          st.push(arr[n-1]);
          for(int i = n-2;i>=0;i--){
              if(arr[i] < arr[i+1]){
                  v.push_back(arr[i+1]);
                  st.push(arr[i]);
              }
              else{
                  while(!st.empty() && st.top()<=arr[i]){
                      st.pop();
                  }
                  if(st.empty()){
                    v.push_back(-1);
                  }
                  if(!st.empty()){
                    v.push_back(st.top());
                  }
                  st.push(arr[i]);
              }
          }
          reverse(v.begin(),v.end());
           int c = -1;
          for(int i = 0;i<v.size();i++){
              if(v[i] == -1){
                  c = i;
              }
          }
          for(int i = 0;i<c;i++){
              q.push_back(arr[i]);
          }
          for(int i = c;i>=0;i--){
              if(v[i] == -1){
                 while(!q.empty() && q.front()<=arr[i]){
                     q.pop_front();
                 }
                 if(!q.empty()){
                     v[i] = q.front();
                 }
              }
              if(!q.empty()){
                q.pop_back();
              }
          }
          return v;
    }
};