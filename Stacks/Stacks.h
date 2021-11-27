// Student ID: 20399730
#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>

class Stack_Int{
private:
    std::vector<int> _data;
    
public:
    size_t size() const
    {
        return _data.size();
    }
    bool is_empty() const
    {
        return _data.empty();
    }
    void push(int val)
    {
        _data.push_back(val);
    }
    int top(bool& success) const
    {
        if(!is_empty())
        {
            success = true;
            return _data.back();
        }
        else
        {
        success = false;
        return 0;
        }
    }
    bool pop()
    {
        if(!is_empty())
        {
            _data.pop_back();
            return true;
        }

        return false;
    }
    bool pop(int& val)
    {
        if(!is_empty())
        {
            val = _data.back();
            _data.pop_back();
            return true;
        }

        return false;
    }

    std::string to_string() const
    {
        std::string str = "Stack (" + std::to_string(_data.size()) + " elements):\n";
        if(size() > 10)
        {
            for(size_t i=0;i <10 ;i++)
            {
                str += std::to_string(_data[_data.size()-1-i])+"\n";
            }
            str += "...";
        }
        else
        {
            for(int i=_data.size()-1;i >= 0 ;i--)
            {
                str +=std::to_string( _data[i])+" ";

            }
        }

        str += "\nElements, if listed above, are in increasing order of age.";

        return str;
    }
    friend class Tests;
};
class Stack_String {
private:
    std::vector<std::string> _data;
public:
    size_t size() const {
        return _data.size();
    }
    bool is_empty() const {
        return _data.empty();
    }
    void push(std::string val) {
        _data.push_back(val);
    }
    std::string top(bool& success) const {
        if(!is_empty())
        {
            success = true;
            return _data.back();
        }
        else
        {
            success = false;
            return 0;
        }

    }
    bool pop() {
        if(!is_empty())
        {
            _data.pop_back();
            return true;
        }

        return false;
    }
    bool pop(std::string& val) {

        if(!is_empty())
        {
            val = _data.back();
            _data.pop_back();
            return true;
        }

        return false;
    }
    std::string to_string() const
    {
        std::string str = "Stack (" + std::to_string(_data.size()) + " elements):\n";
        if(size() > 10)
        {
            for(size_t i=0;i <10 ;i++)
            {
                str += _data[_data.size()-1-i]+"\n";
            }
            str += "...";
        }
        else
        {
            for(int i=_data.size()-1;i >= 0 ;i--)
            {
                str += _data[i]+" ";
            }
        }
        str += "\nElements, if listed above, are in increasing order of age.";
        return str;
    }
    // Don't remove the following line
    friend class Tests;
};
#endif /* Stacks_h */
