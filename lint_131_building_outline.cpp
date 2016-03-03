#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int> > outline;
        int length = 0;
        for(vector<vector<int> >::iterator it=buildings.begin(); it!=buildings.end(); it++){
            length = max((*it)[1], length);
        }
        cout << length << endl;

        vector<int> horizon(length+1+1, 0);
        for(vector<vector<int> >::iterator it=buildings.begin(); it!=buildings.end(); it++){
            for(int i=(*it)[0]; i<=(*it)[1]; i++)
                horizon[i] = (*it)[2];
        }

        int last_height = 0;
        int start = 0;
        for(int i=1;i<horizon.size();i++){
            cout << horizon[i] << endl;
            if(last_height == horizon[i])
                continue;

            // new building
            if(last_height==0){
                start = i;
                last_height = horizon[i];
                continue;
            }

            // end building
            vector<int> building(3,0);
            building[0] = start;
            building[1] = i-1;
            building[2] = last_height;
            outline.push_back(building);

            // change building
            start = i;
            last_height = horizon[i];
        }

        return outline;
    }
};

int main(int argc, char* argv[]){
    Solution sol;

    int arr1[] = {1, 3, 3};
    int arr2[] = {2, 4, 4};
    int arr3[] = {5, 6, 1};
    vector<vector<int> > buildings;
    buildings.push_back(vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[0])));
    buildings.push_back(vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[0])));
    buildings.push_back(vector<int>(arr3, arr3+sizeof(arr3)/sizeof(arr3[0])));

    vector<vector<int> > outline = sol.buildingOutline(buildings);
    for(vector<vector<int> >::iterator it=outline.begin(); it!=outline.end(); it++)
    {
        for(vector<int>::iterator itt=it->begin(); itt!=it->end(); itt++)
            cout << *itt << " ";
        cout << endl;
    }
    return 0;
}
