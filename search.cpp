#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

std::vector<std::string> results;                // holds search results

// recursive search algorithm
void search(const std::string &curr_directory, const std::string &extension) {

    path p(curr_directory);
    for (auto i = directory_iterator(p); i != directory_iterator(); i++) {

        if (is_directory(i->path())) {

            std::string fname = i->path().string();
            cout << "Folder : " + fname << endl;

            if (fname != "." && fname != "..")

                search(fname, extension);    // search through it

        } else if (is_regular_file(i->path())) {

            std::string fname = i->path().filename().string();
            cout << "File : " + fname << endl;

            // if filename's last characters are extension
            if (fname.find(extension, (fname.length() - extension.length())) != std::string::npos)

                results.push_back(fname);        // add filename to results vector

        } else continue;

    }

}

int main(int argc, char *argv[]) {                // accepts command line arguments

    // obtain user input, file type to search for
    std::string extension;                        // type of file to search for

    if (argc < 2) {                                // if user did not provide command line arguments

        std::cout << "Please enter the extension you would like to search for." << std::endl;
        std::cin >> extension;

    } else                                        // if user did provide command line arguments
        extension = argv[1];

    // setup search parameters
//    std::string curr_directory = get_current_dir_name();
//    std::string curr_directory = std::experimental::filesystem::current_path().string();
    search("F:\\DK-HP-PA-2000AR\\Songs", extension);

    // output results
    if (!results.empty()) {

        std::cout << results.size() << " files were found:" << std::endl;

        for (const auto &result : results)    // used unsigned to appease compiler warnings

            std::cout << "- \t" << result << std::endl;

    } else {

        std::cout << "No files ending in '" << extension << "' were found." << std::endl;
    }

    // return
    return 0;
}
