// Dynamic Programming solution to 0-1 Knapsack Problem.
#include<iostream>
#include<vector>

using namespace std;

long long knapsack(long long total_weight, long long total_items, vector<long long> values)
{
    vector< vector<long long> > max_values(total_weight + 1, vector<long long>(total_items + 1));
    int temp_value = 0;

    for(long long i = 0; i <= total_items; i++)
    {
        max_values[0][i] = 0;
    }
    for(long long i = 0; i <= total_weight; i++)
    {
        max_values[i][0] = 0;
    }

    for(long long i = 1; i <= total_items; i++)
    {
        for(long long j = 1; j <= total_weight; j++)
        {
            max_values[j][i] = max_values[j][i - 1];

            if(values[i - 1] <= j)
            {
                temp_value = max_values[j - values[i - 1]][i - 1] + values[i - 1];
            }
            if(temp_value > max_values[j][i])
            {
                max_values[j][i] = temp_value;
            }
            temp_value = 0;
        }
    }

    return max_values[total_weight][total_items];
}

int main()
{
    long long total_weight = 0;
    long long total_items = 0;

    cin>>total_weight>>total_items;

    vector<long long> values(total_items);
    for(long long i = 0; i < total_items; i++)
    {
        cin>>values[i];
    }

    cout<<knapsack(total_weight, total_items, values)<<endl;
    return 0;
}