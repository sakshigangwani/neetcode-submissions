class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string folder;
        stringstream ss(path);

        while(getline(ss, folder, '/')){
            if(folder.empty() || folder == "."){
                continue;
            }

            if(folder == ".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(folder);
            }
        }

        string result;
        for(auto folder : st){
            result += "/" + folder;
        }

        return result.empty() ? "/" : result;
    }
};