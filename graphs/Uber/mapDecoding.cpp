int mapDecoding(string message) {
    if (message == "")
        return 1;
    if (message[0] == '0')
        return 0;
    long mod = 1e9+7;
    long x = 1; // after 0 digits
    long y = 1; // after 1 digit
    for (int i = 1; i < message.size(); ++i) {
        long z = 0;
        if (message[i] != '0')
            z += y;
        if (message[i-1] != '0' && (message[i-1]-'0')*10+message[i]-'0' <= 26)
            z += x;
        x = y;
        y = z%mod;
    }
    return y;
}