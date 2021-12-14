#include <iostream>
#include <vector>
#include <set>

template <typename K, typename V>
class map {
private:

    K Key;
    V Value;

    std::vector<std::pair<K, V>>Vec;

public:
    void insert(K const& key, V const& value) {
        std::pair<K, V>pr;
        pr.first = key;
        pr.second = value;

        Vec.push_back(pr);
    }

    void print(K const& key) {

        std::set<std::pair<K, V>>st;

        // SORTING
        for (int i = 0; i < Vec.size(); i++) { st.emplace(Vec[i]); }
        Vec.clear();
        for (auto el : st) { Vec.push_back(el); }
        st.clear();
        // ######

        for (int i = 0; i < Vec.size(); i++) {
            if (key == Vec[i].first) std::cout << " Value: " << Vec[i].second << " Position: " << i;
        }
        std::cout << std::endl << std::endl;
    }

    void ShowALL() {

        std::cout << "   -- ALL elements --" << std::endl;
        for (int i = 0; i < Vec.size(); i++)
        {
            std::cout << " Key: " << Vec[i].first;

            // SMOOTH OUTPUT
            int _size = 0;
            int _sizeWord = Vec[i].first.size();
            while (_sizeWord != 10) {
                _size++;
                _sizeWord++;
            }
            for (int i = 0; i < _size; i++) std::cout << " ";
            std::cout << "| "


                "Value: " << Vec[i].second << std::endl;
        }
        std::cout << std::endl;
    }

    void pop(K const& key) {
        for (int i = 0; i < Vec.size(); i++) {
            if (key == Vec[i].first) {
                std::cout << "  " << Vec[i].second << " - Deleted " << " | Position:  " << i << std::endl << std::endl;
                Vec.erase(Vec.begin() + i);
            }
        }
    }


    void GetKeys() {
        std::cout << "   -- KEYS -- " << std::endl;
        for (int i = 0; i < Vec.size(); i++) std::cout << "|  " << Vec[i].first << std::endl;
        std::cout << std::endl;
    }

    int size() { return Vec.size(); }

    void clear() {
        std::cout << "| Map is clear";
        Vec.clear();
    }

};

int main() {

    map<std::string, int>mp;

    mp.insert("Hello", 7);
    mp.insert("Asio", 12);
    mp.insert("Assembly", 18);
    mp.insert("Fill", 17);
    mp.insert("Deep", 17);
    mp.insert("Good", 17);
    mp.insert("Yml", 17);
    mp.insert("Cmake", 17);
    mp.insert("Cpp", 23);

    mp.print("Deep");
    mp.ShowALL();

    mp.pop("Asio");
    mp.ShowALL();

    mp.GetKeys();

    mp.clear();

}