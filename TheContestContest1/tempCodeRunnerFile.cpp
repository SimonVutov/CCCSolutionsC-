

    vector<int> sum (n+1, 0); // a to b inclusive is sum[b+1] - sum[a]
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + v[i];
    }