void Replace(string& s, const string& oldVal, const string& newVal)
{
    for (auto beg = s.begin(); std::distance(beg, s.end()) >=
                               std::distance(oldVal.begin(), oldVal.end());) {
        if (string{beg, beg + oldVal.size()} == oldVal) {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            std::advance(beg, newVal.size());
        }
        else
            ++beg;
    }
}
