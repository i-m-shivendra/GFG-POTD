struct compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second == b.second) 
            return a.first > b.first;
        return a.second < b.second;
    }
};


class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
     
        int sum=0;
        for(int i=0;i<k;i++)
        {
            m[arr[i]]++;
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            pq.push({i->first,i->second});
        }
        auto ini = pq.top();
        //cout<<ini.first<<endl;
        sum += ini.first;
        int i=0;
        int j=k;
        while(j<arr.size())
        {
            m[arr[j]]++;
            pq.push({arr[j],m[arr[j]]});
            j++;
            m[arr[i]]--;
            pq.push({arr[i],m[arr[i]]});
            i++;
            
            auto ini = pq.top();
            while(!pq.empty() && m[ini.first]!=ini.second)
            {
                pq.pop();
                ini = pq.top();
            }
            //cout<<ini.first<<endl;
            sum += ini.first;
        }
        return sum;
    }
};

