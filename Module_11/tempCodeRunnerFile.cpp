vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end()); 

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;