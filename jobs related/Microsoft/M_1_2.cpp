/*
这道题的关键就是，同一个节点的两个子节点，距离为2，根据这个因素，可以判断各个节点的父节点，
同时非叶子节点的间距，可以根据子树叶子节点计算出来。
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M, K;
    cout<<"input N, M, K: "<<endl;
    cin>>N>>M>>K;

    cout<<"input number of nodes in each depth: "<<endl;
    vector<int> number_of_nodes;

    for(int i = 0; i < M; ++i)
    {
        int number;
        cin>>number;
        number_of_nodes.push_back(number);
    }

    cout<<"input id of nodes in each depth: "<<endl;
    vector<vector<int>> nodes_in_depth;

    for(int i = 0; i < M; ++i)
    {
        vector<int> nodes_in_depth_son;
        for(int j = 0; j < number_of_nodes[i]; ++j)
        {
            int id;
            cin>>id;
            nodes_in_depth_son.push_back(id);
        }
        nodes_in_depth.push_back(nodes_in_depth_son);
    }

    cout<<"input id of leaves: "<<endl;
    vector<int> id_of_leaves;
    map<int, int> map_id_of_leaves;
    for(int i = 0; i < K; ++i)
    {
        int id;
        cin>>id;
        id_of_leaves.push_back(id);
        map_id_of_leaves[id] = i;
    }

    cout<<"input distance between leaves: "<<endl;
    vector<vector<int>> distance_between_leaves;
    
    for(int i = 0; i < K; ++i)
    {
        vector<int> distance_between_leaves_son;
        for(int j = 0; j < K; ++j)
        {
            int dis;
            cin>>dis;
            distance_between_leaves_son.push_back(dis);
        }
        distance_between_leaves.push_back(distance_between_leaves_son);
    }

    map<int, bool> check_isleaves;

    for(int i = 0; i < nodes_in_depth.size(); ++i)
    {
        for(int j = 0; j < nodes_in_depth[i].size(); ++j)
        {
            check_isleaves[nodes_in_depth[i][j]] = false;
        }
    }

    for(int i = 0; i < id_of_leaves.size(); ++i)
    {
        check_isleaves[id_of_leaves[i]] = true;
    }

    map<int, int> parent_node;
    map<int, int> child_node;
    map<int, pair<int, int>> distance_from_nodes_to_leaves;

    for(int i = M - 1; i >= 0; i--)
    {
        if(i==0)
        {
            cout<<"Entering i == 0: "<<endl;
            for(int j = 0; j < number_of_nodes[i]; j++)
            {
                parent_node[nodes_in_depth[i][j]] = 0;
                cout<<nodes_in_depth[i][j]<<" ";
            }
        }
        else
        {
            cout<<"Entering i != 0: "<<endl;
            int current_parent_id = nodes_in_depth[i-1][0];
            int prev_node = nodes_in_depth[i][0];
            for(int j = 0; j < number_of_nodes[i]; j++)
            {
                if(j == 0)
                {
                    cout<<"Entering j == 0: "<<endl;
                    while(check_isleaves[current_parent_id])
                    {
                        ++current_parent_id;
                    }
                    parent_node[nodes_in_depth[i][j]] = current_parent_id; 
                    child_node[current_parent_id] = nodes_in_depth[i][j];

                    cout<<"parent_node: "<<current_parent_id<<" child_node: "<<nodes_in_depth[i][j]<<endl;

                    if(!check_isleaves[nodes_in_depth[i][j]])
                    {                
                        int child = child_node[nodes_in_depth[i][j]];
                        if(check_isleaves[child])
                        {
                            pair<int, int> p(child, 1);
                            distance_from_nodes_to_leaves[nodes_in_depth[i][j]] = p;
                        }
                        else
                        {
                            pair<int, int> p = distance_from_nodes_to_leaves[child];
                            pair<int, int> new_p(p.first, p.second + 1);
                            distance_from_nodes_to_leaves[nodes_in_depth[i][j]] = new_p;
                        }
                    }

                }
                else
                {
                    cout<<"Entering j != 0: "<<endl;
                    if(check_isleaves[nodes_in_depth[i][j]])
                    {
                        cout<<"Entering check_isleaves is true: "<<endl;
                        int dis = 0;

                        if(check_isleaves[prev_node])
                        {
                           // dis = distance_between_leaves[prev_node][nodes_in_depth[i][j]];
                           dis = distance_between_leaves[map_id_of_leaves[prev_node]][map_id_of_leaves[nodes_in_depth[i][j]]];
                        }
                        else
                        {
                            pair<int, int> p = distance_from_nodes_to_leaves[prev_node];
                            //dis = distance_between_leaves[p.first][nodes_in_depth[i][j]];
                            dis = distance_between_leaves[map_id_of_leaves[p.first]][map_id_of_leaves[nodes_in_depth[i][j]]];
                            dis = dis - p.second;
                        }

                        if(dis == 2)
                        {
                            parent_node[nodes_in_depth[i][j]] = current_parent_id;
                            child_node[current_parent_id] = nodes_in_depth[i][j];
                        }
                        else
                        {
                            ++current_parent_id;
                            while(check_isleaves[current_parent_id])
                            {
                                ++current_parent_id;
                            }
                            parent_node[nodes_in_depth[i][j]] = current_parent_id; 
                            child_node[current_parent_id] = nodes_in_depth[i][j];
                        }

                        cout<<"parent_node: "<<current_parent_id<<" child_node: "<<nodes_in_depth[i][j]<<" dis: "<<dis<<endl;
                    }
                    else
                    {
                        cout<<"Entering check_isleaves is false: "<<endl;
                        int child = child_node[nodes_in_depth[i][j]];
                        cout<<"node: "<<nodes_in_depth[i][j]<<" child: "<<child<<endl;

                        pair<int, int> new_p;

                        if(check_isleaves[child])
                        {
                            pair<int, int> p(child, 1);
                            new_p = p;
                            distance_from_nodes_to_leaves[nodes_in_depth[i][j]] = new_p;
                        }
                        else
                        {
                            pair<int, int> p = distance_from_nodes_to_leaves[child];
                            pair<int, int> new_pp(p.first, p.second + 1);
                            new_p = new_pp;
                            distance_from_nodes_to_leaves[nodes_in_depth[i][j]] = new_p;
                        }

                        cout<<"new_p first: "<<new_p.first<<" second: "<<new_p.second<<endl;
                        int dis = 0;

                        if(check_isleaves[prev_node])
                        {
                            //dis = distance_between_leaves[new_p.first][prev_node];
                            dis = distance_between_leaves[map_id_of_leaves[new_p.first]][map_id_of_leaves[prev_node]];
                            cout<<"dis 1: "<<dis<<endl;
                            dis = dis - new_p.second;
                            cout<<"dis 2: "<<dis<<endl;
                        }
                        else
                        {
                            pair<int, int> p_1 = distance_from_nodes_to_leaves[prev_node];
                            //dis = distance_between_leaves[new_p.first][p_1.first];
                            dis = distance_between_leaves[map_id_of_leaves[new_p.first]][map_id_of_leaves[p_1.first]];
                            dis = dis - new_p.second - p_1.second;
                        }

                        if(dis == 2)
                        {
                            parent_node[nodes_in_depth[i][j]] = current_parent_id;
                            child_node[current_parent_id] = nodes_in_depth[i][j];
                        }
                        else
                        {
                            ++current_parent_id;
                            while(check_isleaves[current_parent_id])
                            {
                                ++current_parent_id;
                            }
                            parent_node[nodes_in_depth[i][j]] = current_parent_id; 
                            child_node[current_parent_id] = nodes_in_depth[i][j];
                        }

                        cout<<"parent_node: "<<current_parent_id<<" child_node: "<<nodes_in_depth[i][j]<<" dis: "<<dis<<endl;

                    }

                    prev_node = nodes_in_depth[i][j];
                }
            }
        }
    }


    vector<int> res;
    for(int i = 1; i <= N; ++i)
    {
        res.push_back(parent_node[i]);
    }

    cout<<"Result is: "<<endl;
    for(int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}