#include <iostream>
#include <vector>


int main(){
    std::vector<int> v;
    int i;

    std::cout << "vector size = " << v.size() << std::endl;

    for(i = 0; i < 5; i++){
        v.push_back(i);
    }

    std::cout << "extended vector size = " << v.size() << std::endl;

    for(i = 0; i < 5; i++){
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
    }

    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << "value of v = " << *it << std::endl;
        it++;
    }
    return 0;
}