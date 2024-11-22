struct Time {
    // instance variables
    int hour, minute;
    double second;

    // constructors
    Time(int, int, double);
    Time();

    // modifiers
    void increment(double);

    // functions
    string to_string(int);
};
