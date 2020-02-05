bool isBetween(double a, double b) {
    if (floor(a) != floor(b)) {
        return true;
    } else {
        return false;
    }
}
double minDist(double a, double b) {
    double dist = 0.0;
    // if there is road between them
    if (isBetween(a,b)) {
        dist = std::abs(a-b);
    } else {
        if (a == b) return 0.0;
        double left = (b - std::floor(b)) +  (a - std::floor(a));
        double right = (std::ceil(b) - b) + (std::ceil(a) - a);
        if (left > right) 
            return right;
        else 
            return left; 
    }
    return dist;
}

double perfectCity(std::vector<double> departure, std::vector<double> destination) {
    double minHori = 0.0;
    double minVert = 0.0;
    minHori = minDist(departure[0], destination[0]);
    minVert = minDist(departure[1], destination[1]);
    return minHori + minVert;
}
