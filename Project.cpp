#include <iostream>
#include <array>
#include <string>
#include <utility>
// std::array <std::string ,100 > Users;
std::array<std::pair<std::string, int>, 100> singUpData;

void menu()
{
    std::cout << "Please Select An Option:\n";
    std::cout << "1-Add Record.\n";
    std::cout << "2-Fetch Record.\n";
    std::cout << "3-Quit.\n";
}

enum class option
{
    init = 0,
    add = 1,
    fetch = 2,
    quit = 3
};
std::istream &operator>>(std::istream &input_stream, option &result)
{
    int int_option;
    input_stream >> int_option;
    result = static_cast<option>(int_option);
    return input_stream;
}
// option operator-(option & input_stream, int & input2)
// {
//     int int_option;
//     int_option= (static_cast<int>(input_stream))-input2;
//     result=static_cast<option>(int_option);
//     return int_option;
// }
option user_selection()
{
    option result = option::init;
    std::cin >> result;
    return result;
}
void save_array(std::string &name, int &age)
{
    static int id = 0;

    singUpData[id] = std::make_pair(name, age);

    id++;
    std::cout << "User Record Added Successfully \n";
}
void fetch_array(int i)
{
    int Loc_ID = 0;
    Loc_ID = static_cast<int>(i);
    std::cout << "Your User Name is " << singUpData[Loc_ID].first << "\nYour Age is " << singUpData[Loc_ID].second << "\n\n";
}

int main()
{
    std::cout<<"User SignUp Application\n\n";
    option Id = option::init;
    std::string name = "";
    int age = 0;
    option Selection = option::init;

    do
    {

        menu();
        Selection = user_selection();

        switch (Selection)
        {
        case option::add:
        {
            std::cout << "Enter Your username : ";
            std::cin>> name;
            std::cout << "Enter Your age : ";
            std::cin >> age;
            save_array(name, age);
            break;
        }
        case option::fetch:
        {
            std::cout << "Please Enter the ID You want :";
            std::cin >> Id;
            int int_id = (static_cast<int>(Id));
            fetch_array(int_id - 1);
            break;
        }
        case option::quit:
        { /* Add */
            std::cout << "GoodBye\n";
            return 0;
            break;
        }
        default:
        { /*do nothing*/

            std::cout << "Error : Please select again\n\n";
            break;
        }
        }
    } while (1);
    return 0;
}