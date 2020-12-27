#ifndef FOOD_H_
#define FIND_H_

class Food
{
    private: 
        double calories;

    public:
        virtual double percent_protein() const = 0;
        virtual double percent_fat() const = 0;
        virtual double percent_carbohydrates() const = 0;

        virtual ~Food() {}

        double get_calories() const {return calories};

        void set_calories(double cal)
        {
            calories = cal;
        }
};

#endif