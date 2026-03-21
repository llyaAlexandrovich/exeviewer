#include "main.hpp"








int main(int argc, char **argv)
{
    std::string ExecutableName;    
    std::vector<std::string> Arguments;
    for(int counter = 0; counter < argc; ++counter)
    {
        Arguments.push_back(std::string{argv[counter]});
    }


    for(int counter = 0; counter < Arguments.size(); ++counter)
    {
        if(Arguments[counter] == "-H" || Arguments[counter] == "--help")
        {
            std::cout << HelpPage << std::endl;
            return EXIT_SUCCESS;
        }
        else if(Arguments[counter] == "-E" || Arguments[counter] == "--exec")
        {
            ExecutableName = Arguments[counter + 1];
            ++counter;
        }
        else ExecutableName = std::move(Arguments[counter]);
        //else if(Arguments[counter] == "-SL" || Arguments[counter] == "--show-less") DoShowLess = true;
    }
    



    std::unique_ptr<ExeViewer::ExeFormat> CurrentFormat = std::make_unique<ExeViewer::ExeFormat>(std::move(ExecutableName));
    CurrentFormat->Init();
    CurrentFormat->PrintInfo();

    
    return EXIT_SUCCESS;
};
