#include <iostream>
#include <vector>
#include <set>

template <typename K, typename V>
class Hash {
private:

	K Key;
	V Value;

	std::vector<std::pair<K, V>>Vec;

public:
	void insert(K key, V value) {
		std::pair<K, V>pr;
		pr.first = key;
		pr.second = value;

		Vec.push_back(pr);
	}

	void print(K key) {

		std::set<std::pair<K, V>>st;

		for (int i = 0; i < Vec.size(); i++) { st.insert(Vec[i]); }
		Vec.clear();

		for (auto el : st) {
			Vec.push_back(el);
		}
		st.clear();

		for (int i = 0; i < Vec.size(); i++) {
			if (key == Vec[i].first) {
				std::cout << Vec[i].second;
			}
		}
		std::cout << std::endl;
	}

	void ShowALL() {
		for (int i = 0; i < Vec.size(); i++) {
			std::cout << " Key: " << Vec[i].first << " Value: " << Vec[i].second << std::endl;
		}
	}

};


int main() {

	Hash<std::string, int>hs;
	hs.insert("Hello", 7);
	hs.insert("Asio", 12);
	hs.insert("Boo", 18);
	hs.insert("Fill", 17);
	hs.insert("Cool", 17);
	hs.insert("Cpp", 23);
	hs.print("Cpp");


	hs.ShowALL();
	
	
}