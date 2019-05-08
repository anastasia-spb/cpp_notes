#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <set>


/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
*/

int find_the_one_missing_int()
{
    std::vector<int> input = { 9,6,4,2,3,5,7,0,1 };
    int max = 0;
    int sum = 0;
    bool zero_present = false;

    for (auto el : input)
    {
        sum += el;
        if (el > max)
        {
            max = el;
        }
        if (el == 0)
        {
            zero_present = true;
        }
    }

    int expected_sum = max*(max + 1) / 2;

    if (expected_sum == sum && zero_present)
    {
        std::cout << "No number is mising";
        return -1;
    }

    if (expected_sum == sum && !zero_present)
    {
        std::cout << "0 is mising";
        return 0;
    }

    int missing_num = expected_sum - sum;
    std::cout << "Missing number is: " << missing_num << std::endl;

    return missing_num;
}

/* We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself.
 * Now, given an integer n, write a function that returns true
 * when it is a perfect number and false when it is not.
 */
bool is_perfect_number()
{
    /* read user input */
    int input_number = -1;
    std::cout << "Give an integer: ";
    std::cin >> input_number;

    /* check if perfect */
    if (input_number <= 0)
    {
        std::cout << "Number is zero or negative.\n";
        return false;
    }

    int sum = 1;

    for (auto i = 2; i < input_number; ++i)
    {
        if (input_number % i == 0)
        {
            sum += i;
            if (sum > input_number)
            {
                break;
            }
        }
    }

    if (sum == input_number)
    {
        std::cout << "Number is perfect." << std::endl;
        return true;
    }


    std::cout << "Input number is " << input_number << ". Sum of its positive divisors is " << sum << ". Number is not perfect." << std::endl;

    return false;
}

/* Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
*/
void flip_matrix()
{

}


/* Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
*/
bool is_follow_pattern()
{
    std::vector<std::pair<char, bool>> pattern;
    std::string pattern_line;

    std::cin.ignore(); /* < to ignore whitespace input */

    std::cout << "Type pattern: ";
    std::getline(std::cin, pattern_line);

    for (auto c : pattern_line)
    {
        pattern.emplace_back(c, false);
    }

    std::string input_line;
    std::cout << "Type string: ";
    std::getline(std::cin, input_line);

    std::istringstream iss(input_line);
    std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
        std::istream_iterator<std::string>{} };

    /* first check that sizes are equal */
    if (pattern.size() != tokens.size())
    {
        std::cout << "false" << std::endl;
        return false;
    }

    std::set<std::string> unique_words;
    int unique_words_size = 0;

    for (auto i = 0; i < pattern.size(); ++i)
    {
        if (pattern[i].second)
        {
            continue;
        }

        /* check that world is new */
        unique_words.insert(tokens[i]);
        if (unique_words_size == unique_words.size())
        {
            std::cout << "false" << std::endl;
            return false;
        }

        unique_words_size = unique_words.size();

        for (auto j = i + 1; j < pattern.size(); ++j)
        {
            if (pattern[i].first == pattern[j].first)
            {
                pattern[j].second = true;

                if (tokens[i] != tokens[j])
                {
                    std::cout << "false" << std::endl;
                    return false;
                }
            }
        }
    }

    std::cout << "true" << std::endl;
    return true;
}

int choose_example()
{
    std::cout << "Exit: 0 \n";
    std::cout << "Perfect Number: 1 \n";
    std::cout << "If str follows the same pattern: 3 \n";
    std::cout << "Missing number: 4 \n";
    std::cout << "Choose example to run: ";

    int example_number = 0;
    std::cin >> example_number;

    if (example_number < 0)
    {
        std::cout << "Invalid example number";
    }

    return example_number;
}


void execute_example(int example_number)
{
    switch (example_number)
    {
    case 0:
        break;
    case 1:
    {
        is_perfect_number();
        break;
    }
    case 3:
    {
        is_follow_pattern();
        break;
    }
    case 4:
    {
        find_the_one_missing_int();
        break;
    }
    default:
    {
        std::cout << "Example number " << example_number << " is not implemented yet.";
        break;
    }
    }
}

int main(int argc, char** argv)
{
    int example_number = -1;

    while (example_number != 0)
    {
        example_number = choose_example();
        execute_example(example_number);
        std::cout << std::endl;
    }

    return 0;
}
