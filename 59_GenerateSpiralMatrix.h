#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int topRowIndex = 0;
    int leftColumnIndex = 0;
    int bottomRowIndex = n - 1;
    int rightColumnIndex = n - 1;

    int index = 0;
    while(topRowIndex <= bottomRowIndex && leftColumnIndex <= rightColumnIndex)
    {
        for(auto it = leftColumnIndex; it < rightColumnIndex + 1; ++it)
        {
            matrix[topRowIndex][it] = ++index;
        }

        for(auto it = topRowIndex + 1; it < bottomRowIndex + 1; ++it)
        {
            matrix[it][rightColumnIndex] = ++index;
        }

        if (bottomRowIndex >  topRowIndex)
        {
            for(auto it = rightColumnIndex - 1; it > leftColumnIndex - 1; --it)
            {
                matrix[bottomRowIndex][it] = ++index;
            }
        }

        if (rightColumnIndex > leftColumnIndex)
        {
            for(auto it = bottomRowIndex - 1; it > topRowIndex; --it)
            {
                matrix[it][leftColumnIndex] = ++index;
            }
        }

        ++topRowIndex;
        ++leftColumnIndex;
        --bottomRowIndex;
        --rightColumnIndex;
    }

    return matrix;   
}
