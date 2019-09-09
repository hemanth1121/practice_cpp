#include <iostream>
#include <vector>
using namespace std;

int findAdjacency(vector<int>& arr, int coinFace)
{
    int n = arr.size();
    int ct = 0, maxCount = 0;
    bool flippingDone = false;
    int adj = 0;
    cout << "coinFace: " << coinFace << endl;
    for(int i=0; i<n; ++i)
    {
        cout << "i : " << i << endl;
        if(arr[i] == coinFace)
        {
            cout << "inside if : " << i << endl;
/*            if(i == n-1)
            {
                ++ct;
            }*/
            if(flippingDone)
            {
                maxCount = max(ct, maxCount);
                ct = adj+1;
                adj = 0;
            }
            else if((i < n-1) && arr.at(i+1) == coinFace)
            {
                ++ct;
                maxCount = max(ct, maxCount);
                ct = 0;
            }
            else
            {
                ++ct;
            }
            flippingDone = true;
            
            cout << "ct : " << ct << endl;
        }
        else
        {
            ++adj;
            ++ct;
        }
        cout << "iteration end for -> ct : " << ct << endl;
    }
    maxCount = max(ct,maxCount);
    
    cout <<"maxCount: " << maxCount << endl;
    return maxCount;
}
int findAdjacenectForFliipingCoins(vector<int>& arr)
{
    //int maxCount0 = 0;
    int maxCount0 = findAdjacency(arr, 1);
    int maxCount1 = findAdjacency(arr, 0);
    
    return (max(maxCount0,maxCount1));
}
int main() {
	// your code goes here
	
	vector<int> vect = {0,0,0,0,0,0};
	cout << findAdjacenectForFliipingCoins(vect) << endl;
/*	vector<int> v;
	v.reserve(10);
	std::cout << v.size() << std::endl;*/
	return 0;
}
