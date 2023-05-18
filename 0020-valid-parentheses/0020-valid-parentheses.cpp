class Solution {
public:
    bool isValid(string s) {
        stack<char> running;
        running.push('0');
        char x = s[0];
        int i = 0;

        while(x)
        {
            if (x=='(') running.push('(');
            if (x=='{') running.push('{');
            if (x=='[') running.push('[');

            if (x==')') 
            {
                if (running.top() != '(') return false;
                running.pop(); 
            }

            if (x==']') 
            {
                if (running.top() != '[') return false;
                running.pop(); 
            }

            if (x=='}') 
            {
                if (running.top() != '{') return false;
                running.pop(); 
            }


            i++;
            x = s[i];
        }

        running.pop();
        if (running.empty()) return true;
        return false;
    }
};