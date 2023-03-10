#include <iostream>
#include <vector>

struct Val{
    std::string here{"here"};
    std::vector<int> vals{0};
};

void printv(const std::vector<Val>& v) {
    for(auto i : v) {
        for(auto j : i.vals){
            std::cout << j << ' ';
        }
    }
    std::cout << '\n';
}


int main(int argc, char** argv) {
    std::vector<Val> v1(3);
    v1[0].vals.push_back( 10);
    v1[0].vals.push_back( 11);
    v1[0].vals.push_back( 12);

    // std::vector<Val> v2{{ 6 },{ 7 }, { 8 }, { 9 }};

    // v1.insert(v1.end(), std::make_move_iterator(v2.begin()), std::make_move_iterator(v2.end()));
    std::vector<Val> v2(std::make_move_iterator(v1.begin()), std::make_move_iterator(v1.end()));

    printv(v1);
    printv(v2);

    return 0;
}
