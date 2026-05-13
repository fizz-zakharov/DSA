class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        int n = arr.size();

        int c = n / 2;

        map<int,int> m;

        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<n;i++){

            m[arr[i]]++;

            if(arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        sort(pos.begin(), pos.end());

        // IMPORTANT
        sort(neg.rbegin(), neg.rend());

        // positives + zero
        for(int i=0;i<pos.size();i++){

            int x = pos[i];

            if(m[x] == 0)
                continue;

            // zero special case
            if(x == 0){

                if(m[0] < 2)
                    return false;

                m[0] -= 2;
                c--;

                continue;
            }

            if(m[2*x] > 0){

                m[x]--;
                m[2*x]--;
                c--;
            }
            else{
                return false;
            }
        }

        // negatives
        for(int i=0;i<neg.size();i++){

            int x = neg[i];

            if(m[x] == 0)
                continue;

            if(m[2*x] > 0){

                m[x]--;
                m[2*x]--;
                c--;
            }
            else{
                return false;
            }
        }

        return (c == 0);
    }
};