#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    size_t height = matrix.size();
    size_t width = height == 0 ? 0 : matrix[0].size();

    vector<int> ret(height * width);

    int topRowIndex = 0;
    int leftColumnIndex = 0;
    int rightColumnIndex = width - 1;
    int bottomRowIndex = height - 1;

    int index = 0;
    while(topRowIndex <= bottomRowIndex && leftColumnIndex <= rightColumnIndex)
    {
        for(auto it = leftColumnIndex; it < rightColumnIndex + 1; ++it)
        {
            ret[index++] = matrix[topRowIndex][it];
        }

        for(auto it = topRowIndex + 1; it < bottomRowIndex + 1; ++it)
        {
            ret[index++] = matrix[it][rightColumnIndex];
        }

        if (bottomRowIndex >  topRowIndex)
        {
            for(auto it = rightColumnIndex - 1; it > leftColumnIndex - 1; --it)
            {
                ret[index++] = matrix[bottomRowIndex][it];
            }
        }

        if (rightColumnIndex > leftColumnIndex)
        {
            for(auto it = bottomRowIndex - 1; it > topRowIndex; --it)
            {
                ret[index++] = matrix[it][leftColumnIndex];
            }
        }

        ++topRowIndex;
        ++leftColumnIndex;
        --bottomRowIndex;
        --rightColumnIndex;
    }

    return ret;
}
