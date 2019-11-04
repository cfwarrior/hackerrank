// tag : greedy
int hackerlandRadioTransmitters(vector<int> x, int k) {
    int n = x.size();
    // can use bucket sort to O(n)
    sort(x.begin(), x.end());
    int res = 0, i = 0;
    // the start of block is i, the end of block is x[i] + 2k
    while(i < n) {
        ++res;
        // find best place to place transmitter
        int j = i;
        while(j+1 < n && x[j+1] <= x[i] + k) {
            ++j;
        }
        while(i < n && x[i] <= x[j] + k) {
            i++;
        }
    }
    return res;
}