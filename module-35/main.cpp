#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <filesystem>


void task_01()
{
    auto mass = {1, 2, 3, 4, 5};

    for(const auto& it: mass)
    {
        std::cout << it << std::endl;
    }
};

void task_02()
{
    std::vector<int> vec = {1, 2, 3, 3, 4, 5, 5, 7};

    auto vec_set_func = [vec]()
    {
        std::unordered_set<int> number;

        std::unique_ptr<std::vector<int>> ret = std::make_unique<std::vector<int>>();

        for (const auto& it: vec)
        {
            if (number.count(it) > 0)
              continue;

            number.emplace(it);

            ret->push_back(it);           
        }

        return ret;
    };

    auto ret = vec_set_func();  

    for(const auto& it: *ret.get())
    {
        std::cout << it << std::endl;
    }
};


void task_03()
{
    std::string ext = ".doc";
    std::filesystem::path path = "/home/bender";
    
    auto recursive_get_file_names_by_extension = [](std::filesystem::path path, const std::string ext)
    {
        for(auto& p: std::filesystem::recursive_directory_iterator(path))
        {
            if (p.path().extension().compare(ext) == 0)
            {
                std::cout << p.path() << '\n';
            }
        }
    };

    recursive_get_file_names_by_extension(path, ext);    
};


int main()
{   

    task_01();

    task_02();

    task_03();

    return 0;
}