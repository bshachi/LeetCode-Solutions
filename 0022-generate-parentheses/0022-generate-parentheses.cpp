class Solution {
public:


        
    void AddCombination(int OpenAvailable, int CloseAvailable,string String1,vector<string>& ans)
    {
        if (OpenAvailable == 0 && CloseAvailable == 0)
        {
            ans.push_back(String1);
            return;
        }

        else if (OpenAvailable == CloseAvailable)
        {
            string temp = String1;
            temp.push_back('(');
            AddCombination(OpenAvailable-1, CloseAvailable, temp, ans);
        }

        else if (OpenAvailable == 0)
        {
            string temp = String1;
            temp.push_back(')');
            AddCombination(OpenAvailable, CloseAvailable-1, temp, ans);
        }

        else
        {
            string temp1 = String1;
            temp1.push_back('(');
            AddCombination(OpenAvailable-1, CloseAvailable, temp1, ans);

            string temp2 = String1;
            temp2.push_back(')');
            AddCombination(OpenAvailable, CloseAvailable-1, temp2, ans);
        }
    }


    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        AddCombination(n, n, "", ans);
        return ans;
    }
};