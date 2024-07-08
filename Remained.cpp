// Name: Nafis Uddin


// This project isn't completed. 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

bool validate(string line);
void add(string);
void search(string);
void edit(string);
// void remove(string, string);


//const string database = "database.dat";  
const string database = "E:\\PROBLEM SOLVE\\info.txt";  

// void remove(string line, const string &tempfile)
// {
//     const char * temp = tempfile.c_str();
//     fstream tmp_file(tempfile, ios::in || ios::out || ios::binary);
//     string name = line.substr(2, line.length());
//     string newline;
//     fstream output(database, ios::in | ios::out | ios::binary);
//     if(output)
//     {
//         output.clear();
//         while(getline(output, newline))
//         {
//             if(newline == "") break;
//             if(newline.find(name) == string::npos)
//             tmp_file<<newline<<endl;
//         }
//         output.close();
//     }
//     remove(database.c_str());
//     rename(temp, database.c_str());

// }




void edit(string line)
{
    std::string::size_type index;
    index = line.find("\"", 3);
    string name = line.substr(3, (index-3));
    line = line.substr(index+2);

    index = line.find(' ');
    int field = stoi(line.substr(0, index));
    string value =line.substr(index + 1);

    fstream output(database, ios::in | ios::out | ios::binary);
    
    if(output)
    {
        output.clear();
                while(getline(output, line))
                {
                    if(line == "") break;
                    index = line.find(name);
                    if(index!= string::npos)
                    {
                        std::string::size_type index, length, size;
                        std::streamoff pos = std::streamoff(output.tellg()) - std::streamoff(line.length());
                        if(field == 1)
                        {
                            index = line.find(',', 1);
                            
                            length = line.find(',', index+2);
                            index = index+2;

                            length = length - index;
                            output.seekg(pos+index, ios::beg);
                            size = 9 - (value.length()-1);
                            while(size)
                            {
                                output<<"0";
                                size = size -1;
                                index++;
                            }
                            
                            line.replace(index, length, value);
                            output<<line;

                        }

                        // if(field == 2)
                        // {
                        //     int index = line.find(',', 2);
                        //     cout<<index;
                        // }

                        // if(field == 3)
                        // {
                        //     int index = line.find(',', 3);
                        //     cout<<index;
                        // }
                    }
                }

        output.close();
    }

}



int main(){
/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */
   string temp;  //variable for database filename
   string batch; //variable for batch filename

//    cout<<"Enter Database Name: ";
//    cin>>temp;

//    ifstream infile(temp, ios::binary);
//    ofstream outfile(database, ios::binary);
   string line;
//    if (infile)
//         while (infile.good())
//         {
//             getline(infile, line);
//             if (line != "")
//                 outfile << line << "\n";
//         }

//    infile.close();
//    outfile.close();
/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */

   //add your code for main here
    string number;
    // cin>>batch;
    batch = "E:\\PROBLEM SOLVE\\vowel.txt";
    fstream batchfile(batch, ios::binary | ios::in | ios::out);

    if(batchfile)
    {
        while(getline(batchfile, line))
        {
            if(line == "") break;
            if(validate(line) == true)
            {
                number = line.substr(0, 1);
                if(number == "1") add(line);
                else if(number == "2") search(line);
                else if(number == "3") edit(line);
                // else if(number == "4") remove(line, temp);
            }
            else  cout<<"Invalid Command"<<endl;
        }
    
        batchfile.close();
    }
}

bool validate(string line)
{
    if(line.empty()) return false;
    if(!isdigit(line.at(0))) return false;
    int number = stoi(line.substr(0, 1));
    if(number != 1 && number != 2 && number != 3 && number != 4)  return false;
    if(!isspace(line.at(1))) return false;

    if(number == 1)
    {
        std::string::size_type index, length;
        index = 0, length = 0;
        if(line.find('"'))  index = line.find('"');
        else return false;

        if(line.find('"', index+1))  index = line.find('"', index+1);
        else return false;

        if(!isspace(line.at(index+1))) return false;
        
        if(line.find(' ', index+2)!= string::npos) length = line.find(' ', index+2);
        for(auto i = index+2; i<length; i++)
            if(!isdigit(line.at(i))) return false;
        
        if(length - (index+2) >= 10 ) return false;
        if(line.find(' ', length+1) != string::npos) index = line.find(' ', length+1);
        else return false;
        
        for(auto i = length+1; i<index; i++) if(isspace(line.at(i))) return false;
        if((index - (length+1)) >= 4) return false;
        
        if(line.find(' ', index+1) != string::npos) length = line.find(' ', index+1);
        else return false;

        for(auto i = index+1; i<length; i++) {if(!isdigit(line.at(i))) return false;}
        if(length - (index+1) >= 5) return false;
        
        if(line.find('$', length+1) != string::npos) index = line.find('$', length+1);
        else return false;

        if(line.find('.', length+1) != string::npos) length = line.find('.', length+1);
        else return false;

        if(length - (index+1)  >= 5) return false;
        if(line.find("", length+1) != string::npos) index = line.find("", length+1);
        else return false;

        if(index-(length-1) >= 3) return false;
    }

    if(number == 3)
    {
        std::string::size_type index, length;
        if(line.find('"'))  index = line.find('"');
        else return false;

        if(line.find('"', index+1))  index = line.find('"', index+1);
        else return false;

        if(!isspace(line.at(index+1))) return false;
        if(!isdigit(line.at(index+2))) return false;
        if(!isspace(line.at(index+3))) return false;

        index = index+4;
    
        length = line.length() - (index+1);
        
        if((line.at(index-2)) == '1')
        {
            if(length >= 10) return false;

            while(length)
            {
                if(!isdigit(line.at(index))) return false;
                index++;
                length--;
            }

        }

        if(line.at(index-2) == '2')
        {
            if(length >= 4) return false;
            
            while(length)
            {
                if(!isspace(line.at(index))) return false;
                index++;
                length--;
            }
        } 

        if(line.at(index-2) == '3')
        {
            if(length >= 5) return false;
            
            while(length)
            {
                if(!isdigit(line.at(index))) return false;
                index++;
                length--;
            }  
        }
    }

    return true;
}




void add(string line)
{
    fstream output(database, ios::binary | ios::in | ios::out | ios::ate);

    std::string::size_type index;
    index = line.find("\"", 3);
    string name = line.substr(3, (index-3));
    output<<name<<", ";
    line = line.substr(index+2);

    index = line.find(' ');
    string high_score_str = line.substr(0, index);
    int high_score_length = static_cast<int>(index);

    if(high_score_length < 9)
    {
        high_score_length = 9 - high_score_length;
        for(int i = 0; i<high_score_length; i++) output<<"0";
    }

    int high_score = stoi(high_score_str);
    output<<high_score<<", ";
    line = line.substr(index+1);

    index = line.find(' ');
    string initial = line.substr(0, index);
    output<<initial<<", ";
    line = line.substr(index+1);

    index = line.find(' ');
    string played_str = line.substr(0, index);
    int played_length = static_cast<int>(index);

    if(played_length < 4)
    {
        played_length = 4 - played_length;

        for(int i = 0; i<played_length; i++) output<<"0";
    }

    int played = stoi(played_str);
    output<<played<<", $";
    line = line.substr(index+2);

    double revenues = stof(line);
    int revenue = static_cast<int>(revenues);
    int times = 0;
    while(revenue!= 0)
    {
        revenue/= 10;
        times++;
    }
    if(times < 4) 
    {
        times = 4-times;
        for(int i  = 0; i<times; i++) output<<"0";
    }
    
    output<<fixed<<setprecision(2)<<revenues<<endl;

    cout<<"RECORD ADDED"<<endl<<"Name: "<<name<<endl<<"High Score: "<<high_score<<endl
    <<"Initials: "<<initial<<endl<<"Plays: "<<played<<endl<<"Revenue: $"<<fixed<<setprecision(2)<<revenues<<endl<<endl;

    output.close();
}



void search(string search_line)
{
    string search_name = search_line.substr(2);
    string line;

    fstream output(database, ios::in | ios::out | ios::binary);
    if(output)
    {
        output.clear();
        while(getline(output, line))
        {
            if(line == "") break;
            std::string::size_type index;
            index = line.find(search_name);

            if(index != string::npos)
            {
                index = line.find(',');
                string name = line.substr(0, index);
                line = line.substr(index+2);
                index = line.find(' ');
                int high_score = stoi(line.substr(0, index));
                line = line.substr(index+1);

                index = line.find(' ');
                string initial = line.substr(0, index-1);
                line = line.substr(index+1);

                index = line.find(' ');
                int played = stoi(line.substr(0, index));
                line = line.substr(index+2);

                double revenue = stof(line);

                cout<<name<<" FOUND"<<endl<<"High Score: "<<high_score<<endl<<"Initials: "
                <<initial<<endl<<"Plays: "<<played<<endl<<"Revenue: $"<<fixed<<setprecision(2)<<revenue<<endl<<endl;

            }  
        }
        output.close();
    }
}


