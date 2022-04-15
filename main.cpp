#include <iostream>

#include <CLI11/CLI11.hpp>
#include <filesystem>

namespace fs = std::filesystem;
static std::string home = fs::path(getenv("HOME"));
static std::string mainDirectory = home + "/" + "LinZ";


std::string flutterEnv = mainDirectory + "/flutter";
std::string yii2Env = mainDirectory + "/yii2";
std::string wxwidgetsEnv = mainDirectory + "/wxwidgets";
std::string generalCppEnv = mainDirectory + "/general_cpp";

void init() {
    if (!fs::exists(mainDirectory)) {
        fs::create_directory(mainDirectory);
        fs::create_directory(flutterEnv);
        fs::create_directory(yii2Env);
        fs::create_directory(wxwidgetsEnv);
        fs::create_directory(generalCppEnv);
    }

}


int main(int argc, char **argv) {
    init();
    CLI::App app{"Template Engine by Xlogative"};
    bool isFlutter, isYii2, isWxwidgets, isGeneral_cpp;
    app.add_flag("-f,--flutter", isFlutter, "Copy flutter boilerplate code files");
    app.add_flag("-y,--yii2", isYii2, "Copy yii2 boilerplate code files");
    app.add_flag("-x,--wxwidgets", isWxwidgets, "Copy wxwidgets boilerplate code files");
    app.add_flag("-c,--general_cpp", isGeneral_cpp, "Copy general_cpp boilerplate code files");

    CLI11_PARSE(app, argc, argv);

    if (isFlutter) {
        fs::copy(flutterEnv, fs::current_path(), fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "finished copying flutter boilerplate code files\n";
    }
    if (isYii2) {
        fs::copy(yii2Env, fs::current_path(), fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "finished copying yii2 boilerplate code files\n";
    }
    if (isWxwidgets) {
        fs::copy(wxwidgetsEnv, fs::current_path(), fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "finished copying wxwidgets boilerplate code files\n";
    }
    if (isGeneral_cpp) {
        fs::copy(generalCppEnv, fs::current_path(), fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "finished copying general_cpp boilerplate code files\n";
    }





    return 0;

}




/*CLI::App app{"Ticket Engine currently designed for DevCon 2019"};


  app.add_flag("-t,--ticket_id", ticket::is_ticket_id_displayed, "Whether display ticket id or not");

  std::string csv_file_name;
  app.add_option("-c,--csv_file", csv_file_name, "CSV file to generate tickets")
          ->check(CLI::ExistingFile);

  CLI11_PARSE(app, argc, argv);

  if(ticket::is_ticket_id_displayed ) std::cout << "Ticket id is displayed " << std::endl;
  else  std::cout << "Ticket id is not displayed " << std::endl;

  if(csv_file_name.empty()) ticket::generateRawTicket();
  else ticket::generateTicketByCSV(csv_file_name);*/