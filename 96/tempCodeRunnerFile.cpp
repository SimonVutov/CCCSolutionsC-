vector<int> v2FirstOccurance (1000001, -1);
        vector<int> v2LastOccurance (1000001, -1);
        for (int j = 0; j < l; j++) {
            if (v2FirstOccurance[v2[j]] == -1) {
                v2FirstOccurance[v2[j]] = j;
            }
            v2LastOccurance[v2[j]] = j;
        }

        int largest = -1;
        for (int j = 0; j < l; j++) {
            if (v2FirstOccurance[v[j]] != -1) {
                largest = max(largest, j - v2FirstOccurance[v[j]]);
                largest = max(largest, v2LastOccurance[v[j]] - j);
            }
        }

        if (largest == -1) {
            cout << "The maximum distance is 0" << endl;
        } else {
            cout << "The maximum distance is " << largest << endl;
        }