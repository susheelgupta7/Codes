struct thing
{
    int a;
    char b;
    bool operator<(const thing& rhs) const
    {
        return a < rhs.a;
    }
};