class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for(auto& str : strs)
            output += to_string(str.size()) + "#" + str;
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int idx = 0;
        while(idx < s.size()){
            string curr_len;
            while(s[idx] != '#'){
                curr_len += s[idx++];
            }
            int str_len = stoi(curr_len);
            idx++; // across the '#'
            output.push_back(s.substr(idx, str_len));
            idx = idx + str_len;
        }
        return output;
    }
};
