class Solution
{
public:
    Node *solve(Node *node, unordered_map<int, Node *> &mp)
    {

        Node *nodeCopy = new Node(node->val);
        // marked it as visited
        mp[nodeCopy->val] = nodeCopy;

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node *temp = NULL;
            if (mp.count(node->neighbors[i]->val) > 0)
            {
                temp = mp[node->neighbors[i]->val];
            }
            else
            {
                temp = solve(node->neighbors[i], mp);
            }
            nodeCopy->neighbors.push_back(temp);
        }
        return nodeCopy;
    }

    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
        {
            return NULL;
        }
        unordered_map<int, Node *> lookup;
        Node *nodeCopy = solve(node, lookup);
        return nodeCopy;
    }
};