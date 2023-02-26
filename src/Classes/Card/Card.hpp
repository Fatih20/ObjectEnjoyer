#ifndef _CARD_HPP_
#define _CARD_HPP_

template <typename T>
class Card{
    protected:
        T value;
    
    public:
        /**
         * @brief Construct a new Card object with default value NULL
         * 
         */
        Card();

        /**
         * @brief Construct a new Card object with given value
         * 
         * @param value The face value of the card
         */
        Card(T value);
        // CCtor dan assignment operator tidak perlu karena tidak ada pointer
        // Dtor tidak perlu karena hanya menyimpan data sederhana
        // Perlu dipertimbangkan apakah perlu karena T bisa berupa pointer juga (misalnya char*)

        /**
         * @brief Get the face value of the card
         * 
         */
        T getvalue();

        /**
         * @brief Set the face value of the card
         * 
         * @param value 
         */
        void setvalue(T value);
};

#endif