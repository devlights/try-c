
int add(const int values[], const int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += values[i];
    }

    return total;
}
