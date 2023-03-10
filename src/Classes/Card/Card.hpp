#ifndef _CARD_HPP_
#define _CARD_HPP_

template <typename T>
class Card{
    protected:
        T val;
    
    public:
        /**
         * @brief Construct a new Card object with given value
         * 
         * @param value The face value of the card
         */
        Card(T value) {
            this->val = value;
        }
        // CCtor dan assignment operator tidak perlu karena tidak ada pointer
        // Dtor tidak perlu karena hanya menyimpan data sederhana
        // Perlu dipertimbangkan apakah perlu karena T bisa berupa pointer juga (misalnya char*)

        /**
         * @brief Get the face value of the card
         * 
         */
        virtual T value() = 0;

        /**
         * @brief Set the face value of the card
         * 
         * @param value 
         */
        virtual void setValue(T value){
            this->val = value;
        }

        /**
         * @brief Swap the value of two cards with the same type
         * 
         */
        virtual void operator=(Card<T>& other){
            this->setValue(other.value());
        }
};

/**
 * @brief Swap two cards
 * 
 */
template <typename T>
void swap(Card<T>& a, Card<T>& b){
    Card<T> temp = a;
    a = b;
    b = temp;
}

#endif