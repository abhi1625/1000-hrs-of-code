int nightRoute(std::vector<std::vector<int>> city) {
    int start = 0;
    int dist[city.size()];
    bool visited[city.size()];

    for (int i=0; i<city.size(); i++) {
        dist[i] = INT_MAX, visited[i] = false;
    }
    dist[start] = 0;

    for (int count =0; count < city.size(); count++) {
        int nextNode = getNextNode(dist, visited, city.size());
        visited[nextNode] = true;
        for (int v=0; v<city.size(); v++) {
            if (!visited[v] && city[nextNode][v]!= -1 && dist[nextNode]!=INT_MAX && dist[nextNode] + city[nextNode][v] < dist[v] ) {
                dist[v] = dist[nextNode] + city[nextNode][v];
            }
        }
    }
    return dist[city.size() - 1];
}

int getNextNode(int dist[], bool visited[], int num) {
    int min = INT_MAX;
    int minNode;
    for (int n=0; n<num; n++) {
        if(visited[n] == false && dist[n] <= min) {
            min = dist[n];
            minNode = n;
        }
    }
    return minNode;
}
