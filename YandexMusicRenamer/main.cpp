#include "compilation.hpp"

auto main(const int argc, const char* argv[]) -> int
{
	if (argc == 1)
	{
		cout << "I'll help you... Soon..." << endl;
	}
	else if (argc == 2)
	{
		const fs::path dir = fs::current_path();
		if (string(argv[1]) == "--album" || string(argv[1]) == "-a")
			ren::album(dir, true);
		else if (string(argv[1]) == "--band" || string(argv[1]) == "-b")
			ren::band(dir);
		else if (string(argv[1]) == "--compilation" || string(argv[1]) == "-c")
			ren::compilation(dir);
		else
			cout << "Wrong parameter" << endl;
	}
	else if (argc == 3)
	{
		const fs::path dir = fs::current_path() / fs::path(argv[2]);
		if (!exists(dir))
		{
			cout << "Folder does not exist" << endl;
			return 1;
		}

		if (string(argv[1]) == "--album" || string(argv[1]) == "-a")
			ren::album(dir, true);
		else if (string(argv[1]) == "--band" || string(argv[1]) == "-b")
			ren::band(dir);
		else if (string(argv[1]) == "--compilation" || string(argv[1]) == "-c")
			ren::compilation(dir);
	}
	else
	{
		cout << "Wrong parameters" << endl;
	}

	return 0;
}
