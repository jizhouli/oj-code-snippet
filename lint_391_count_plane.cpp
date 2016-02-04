#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int s[], int l, int r)
{
    if (l >= r)
        return;
    //printf("pivot: %d (%d, %d)\n", s[l], l, r);

    int i = l, j = r, x = s[l];
    while(i < j)
    {
        while (i<j && x<=s[j]) j--;
        if (i < j)
            s[i++] = s[j];

        while (i<j && s[i]<x) i++;
        if (i < j)
            s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i-1);
    quick_sort(s, i+1, r);
}

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int iLen = airplanes.size();

        int *iStarts = new int[iLen];
        int *iEnds = new int[iLen];
        for (int i=0; i<iLen; i++) iStarts[i] = airplanes[i].start;
        for (int i=0; i<iLen; i++) iEnds[i] = airplanes[i].end;

        quick_sort(iStarts, 0, iLen-1);
        quick_sort(iEnds, 0, iLen-1);

        int max = 0;
        int sum = 0;
        for (int i=0,j=0; j<iLen;)
        {
            if (i<iLen && iStarts[i]<iEnds[j])
            {
                sum++;
                i++;
            }
            else
            {
                sum--;
                j++;
            }
            if (sum > max)
                max = sum;

            //cout << "sum:" << sum << " max:" << max << endl;
        }
        return max;
    }
};

int main(int argc, char* argv[])
{
    //vector<vector<int> > airplanes = [[1,10],[2,3],[5,8],[4,7]];
    //vector<vector<int> > airplanes(4, vector<int>(2));
    vector<Interval> airplanes;
    airplanes.push_back(Interval(1, 10));
    airplanes.push_back(Interval(2, 3));
    airplanes.push_back(Interval(5, 8));
    airplanes.push_back(Interval(4, 7));
    Solution solution = Solution();
    solution.countOfAirplanes(airplanes);
    return 0;
}
