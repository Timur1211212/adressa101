#include <iostream>
#include <string>
#include <fstream>

class adress {
private:
    std::string city;
    std::string street;
    int house;
    int room;
public:
    adress() : city(""), street(""), house(0), room(0)
    {}

    adress(std::string in_city, std::string in_street, int in_house, int in_room)
    {
        this->city = in_city; this->street = in_street; this->house = in_house; this->room = in_room;
    }

    std::string get_output_address() { std::string result = ""; result = city + " " + street + " " + std::to_string(house) + " " + std::to_string(room);  return result; }
};

int main()
{
    std::ifstream fin("C:\\in.txt");
    std::ofstream fout("C:\\out.txt");

    std::string s;
    fin >> s;
    int size = std::stoi(s);
    adress* mass_address = new adress[size];

    for (int i = 0; i < size; ++i)
    {
        std::string city;
        std::string street;
        int house;
        int room;
        fin >> city;
        fin >> street;
        fin >> s;
        house = std::stoi(s);
        fin >> s;
        room = std::stoi(s);
        mass_address[i] = adress(city, street, house, room);
    }

    fin.close();

    std::string* AS = new std::string[size];
    for (int i = 0; i < size; ++i)
    {
        AS[i] = mass_address[i].get_output_address();
    }
    std::string tmp;
    for (int i = size - 1, j = 0; i >= size / 2; --i, ++j) {
        std::string tmp = AS[i];
        AS[i] = AS[j];
        AS[j] = tmp;
    }


    fout << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        fout << AS[i] << std::endl;
    }

    fout.close();

    delete[] mass_address;

    return 0;
}