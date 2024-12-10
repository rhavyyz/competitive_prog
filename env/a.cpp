#include <bits/stdc++.h>
using namespace std;
 
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define int long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false); 
#define endl '\n'
#define bug(x)  cerr << #x << " >>> " << x << endl;
#define all(A) A.begin(), A.end()

// int n;
const int INF = 1e17;

long long maximumSubarraySum(vector<int> nums, int k) {
    int sum = 0;
    int curr_sum = 0;

    map<int, int> el;

    for(int i = 0; i < k; i++)   
    {
        curr_sum += nums[i];
        el[nums[i]]++;;
    }
    if(el.size() == k)
        sum = max(sum, curr_sum);

    for(int i = k; i< nums.size(); i++)
    {
        curr_sum -= nums[i-k];
        el[nums[i-k]]--;
        if(el[nums[i-k]] == 0)
        {
            el.erase(el.find(nums[i-k]));
        }
        
        el[nums[i]]++;
        curr_sum += nums[i];
        if(el.size() == k)
            sum = max(sum, curr_sum);

    }

    return sum;
}

int solve()
{


    cout <<maximumSubarraySum({1,5,4,2,9,9,9}, 3) << endl;

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;    

    while(t--)
    {
        solve();
    } 
    

    return 0;

}