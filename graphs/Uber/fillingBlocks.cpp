int fillingBlocks(int n) {
    /* dp[1]:
     * ?
     * ?
     * ?
     * ?
     */
    /* half[1]:
     * ?
     * ?
     * x
     * x
     */
    /* mid[1]:
     * x
     * ?
     * ?
     * x
     */
    vector<int> dp(n+1), half(n+1), mid(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        // dp:
        /*
         * A
         * A
         * B
         * B
         */
        dp[i] = dp[i-1];
        /*
         * AA
         * BB
         * CC
         * DD
         */
        if (i >= 2)
            dp[i] += dp[i-2];
        /*
         * AA
         * B
         * B
         * CC
         */
        if (i >= 2)
            dp[i] += mid[i-1];
        /*
         * AA or A
         * BB    A
         * C     BB
         * C     CC
         */
        if (i >= 2)
            dp[i] += 2*half[i-1];
        
        // half:
        /*
         * A
         * A
         * x
         * x
         */
        half[i] = dp[i-1];
        /*
         * AA
         * BB
         * x
         * x
         */
        if (i >= 2)
            half[i] += half[i-1];
        
        // mid:
        /*
         * x
         * A
         * A
         * x
         */
        mid[i] = dp[i-1];
        /*
         * xCC
         * AA
         * BB
         * xDD
         */
        if (i >= 3)
            mid[i] += mid[i-2];
    }
    if (n == 4) {
        for (auto& e : dp)
            cout << e << " ";
        cout << endl;
        for (auto& e : mid)
            cout << e << " ";
        cout << endl;
        for (auto& e : half)
            cout << e << " ";
        cout << endl;
    }
    return dp[n];
}
