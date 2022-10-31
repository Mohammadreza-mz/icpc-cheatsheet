struct Node
{
    char c;
    int parent;
    int isWord;
    int suffLink;
    vi children;
    int len;
    Node(){
        parent = -1;
        isWord = false;
        suffLink = -1;
        children.clear();
        len = 0;
    }
};
struct Aho
{
    vector<Node> nodes;

    Aho(){
        nodes.pub(Node());
        nodes[0].suffLink=0;
    }
    void addString(string s){
        int cur = 0;
        fore(i, 0 , s.size()-1){
            int nxt = -1;
            if (cur < nodes.size())
                fore(j , 0 , nodes[cur].children.size()-1){
                    if (nodes[nodes[cur].children[j]].c == s[i])
                    {
                        nxt = nodes[cur].children[j];
                        break;
                    }
                }
            if (~nxt)
            {
                cur = nxt;
                continue;
            }
            nodes[cur].children.pub(nodes.size());
            nodes.pub(Node());
            nodes[nodes.size()-1].parent = cur;
            nodes[nodes.size()-1].c = s[i];
           
            cur = nodes.size()-1;
        }
        nodes[cur].isWord = true;
        nodes[cur].len = s.size();
    }

    int calc(int cur){
        if (nodes[cur].suffLink == -1)
        {
            if (nodes[cur].parent == 0) return 0;
            return nodes[cur].suffLink = trans(calc(nodes[cur].parent) , nodes[cur].c);
        }
        return nodes[cur].suffLink;
    }
    int res = inf;
    int pos;
    int trans(int cur , char c ){
        if (nodes[cur].isWord){
            res = min(res , pos - nodes[cur].len + 1);
        }
        fore(i,0 , nodes[cur].children.size()-1){
            if (nodes[nodes[cur].children[i]].c == c)
                return nodes[cur].children[i];
        }
        if (cur == 0) return 0;
        return trans(calc(cur) , c);
    }
    int find(string s){
        
        int cur = 0;
        fore(i , 0 , s.size()-1){
            pos = i;
            cur = trans(cur , s[i]);
            if (nodes[cur].isWord){
                res = min(res , i - nodes[cur].len +2);
            }
            calc(cur);
        }
        return res;
    }
};