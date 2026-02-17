#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> bucketSize(3);
    vector<int> capacity(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> bucketSize[i];
        cin >> capacity[i];
    }
    for (int i = 0; i < 100; i++)
    {
        int j = i + 1;
        if (bucketSize[j % 3] - capacity[j % 3] >= capacity[i % 3])
        {
            capacity[j % 3] += capacity[i % 3];
            capacity[i % 3] = 0;
        }
        else
        {
            capacity[i % 3] -= (bucketSize[j % 3] - capacity[j % 3]);
            capacity[j % 3] = bucketSize[j % 3];
        }
    }
    cout << capacity[0] << " " << capacity[1] << " " << capacity[3] << endl;
}