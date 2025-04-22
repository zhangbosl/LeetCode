#pragma once
//#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
//#include <iterator>
//#include <numeric>
//#include <map>
//#include <variant>
//#include <type_traits>
using namespace std;

class Printer {
public:
    string printResult(vector<string> result) {
        string result_string = "[";
        if (!result.empty())
            result_string += "\"" + result[0] + "\"";

        for (int i = 1; i < result.size(); ++i)
            result_string += ",\"" + result[i] + "\"";

        result_string += "]";

        //cout << "Output: " << result_string << endl;
        return result_string;
    }
    string printResult(vector<int> result) {
        string result_string = "[";
        if (!result.empty())
            result_string += "\"" + to_string(result[0]) + "\"";

        for (int i = 1; i < result.size(); ++i)
            result_string += ",\"" + to_string(result[i]) + "\"";

        result_string += "]";

        //cout << "Output: " << result_string << endl;
        return result_string;
    }
    template<typename T>
    string printResult(vector<vector<T>> result) {
        string result_string = "[";
        if (!result.empty()) {
            //result_string += "\"" + to_string(result[0]) + "\"";
            //result_string += "\"" + printResult(result[0]) + "\"";
            result_string += printResult(result[0]);
        }

        for (int i = 1; i < result.size(); ++i) {
            //result_string += ",\"" + to_string(result[i]) + "\"";
            //result_string += ",\"" + printResult(result[i]) + "\"";
            result_string += "," + printResult(result[i]);
        }

        result_string += "]";

        //cout << "Output: " << result_string << endl;
        return result_string;
    }

    // 打印基础类型（int 或 std::string）
    template<typename T>
    void print_element(const T& elem, int indent = 0) {
        std::string indentation(indent, ' ');
        std::cout << indentation << elem << std::endl;
    }

    // 递归打印 vector
    template<typename T>
    void print_vector(const std::vector<T>& vec, int indent = 0) {
        std::string indentation(indent, ' ');
        std::cout << indentation << "[\n";
        for (const auto& elem : vec) {
            print_element(elem, indent + 2);
        }
        std::cout << indentation << "]\n";
    }

    // 专门处理嵌套 vector 的递归打印
    template<typename T>
    void print_element(const std::vector<T>& vec, int indent = 0) {
        print_vector(vec, indent);
    }

    // 使用 std::variant 来存储 int 或 std::string
    //using IntOrString = std::variant<int, std::string>;

    //// 打印 std::variant<int, std::string>
    //void print_element(const IntOrString& elem, int indent = 0) {
    //    std::visit([indent](const auto& value) { print_element(value, indent); }, elem);
    //}

    //// 递归打印 vector<IntOrString>
    //template<>
    //void print_element(const std::vector<IntOrString>& vec, int indent) {
    //    print_vector(vec, indent);
    //}

    //// 打印任意嵌套层数的 vector
    //template<typename T>
    //void print_nested_vector(const std::vector<T>& vec, int indent = 0) {
    //    print_element(vec, indent);
    //}
};