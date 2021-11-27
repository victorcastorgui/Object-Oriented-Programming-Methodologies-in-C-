// Student ID: 20399730
// TODO - Replace the number above with your actual student ID
//
// Pet_Store.h
//

#ifndef Pet_Store_h
#define Pet_Store_h

#include <algorithm> // Needed for sort
#include <vector>

#include "Pet.h"

class Pet_Store {
    private:
    std::vector<Pet> _pets;
        
        enum _SORT_ORDER {
            BY_ID,
            BY_NAME,
            NONE
        };
        
        _SORT_ORDER _sort_order = BY_ID;
        
        // Provided functions (no points)
        static bool _id_compare(const Pet& pet1, const Pet& pet2);
        static bool _name_compare(const Pet& pet1, const Pet& pet2);
        void _sort_pets_by_id();
        void _sort_pets_by_name();
    
    public:
        Pet_Store(size_t n = 0);
        size_t get_size() const;
        void set_size(size_t n);
        void clear();
        
        void populate_with_n_random_pets(size_t n);
        bool find_pet_by_id_lin(long id, Pet& pet);
        bool find_pet_by_id_bin(long id, Pet& pet);
        bool find_pet_by_name_lin(string name, Pet& pet);
        bool find_pet_by_name_bin(string name, Pet& pet);
        
        // Return a string with the concatenated string reps of valid pets with
        // index n1 to n2-1 (inclusive)
        std::string to_string(size_t n1, size_t n2);
        
        // Don't remove the following line
        friend class Tests;
};

#endif /* Pet_Store_h */
