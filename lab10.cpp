/*#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream file ("/home/localhostj/Documents/input.txt");
    std::ofstream output_file("/home/localhostj/Documents/output.txt");
    if (!output_file) {
        std::cerr << "Не удалось открыть выходной файл!" << std::endl;
        return 1;
    }

    bool comment_flag = false;
    std::string line;
    while (std::getline(file, line)) {
        std::size_t comment_position = line.find("//");
         std::size_t start_comment_position = line.find("/*");
        // std::size_t end_comment_position = line.find("*///"); // тут убрать // в find
        /*
        if (comment_flag) {
            if (end_comment_position != std::string::npos) {
                comment_flag = false;
                line = line.substr(end_comment_position + 2);
            }
            else {
                line = "";
            }
        }
        else if (start_comment_position != std::string::npos) {
            if (end_comment_position != std::string::npos) {
                line = line.substr(0, start_comment_position) + line.substr(end_comment_position + 2);
            }
            else {
                line = line.substr(0, start_comment_position);
                comment_flag = true;
            }
        }
        else if (comment_position != std::string::npos) {
            line = line.substr(0, comment_position);
        }

        if (!line.empty()) {
            output_file << line << '\n';
        }
    }

    file.close();
    output_file.close();

    std::cout << "Комментарии успешно удалены!" << std::endl;
    return 0;
}*/