#ifndef FOOD_H_
#define FOOD_H_

/** Abstract class that models a kind of food. */
class Food {
  // Data Field
  private:
    double calories; 

  public:
    // Abstract Functions
    /** Calculates the percent of protein in a Food object. */
virtual double percent_protein() const = 0;
    /** Calculates the percent of fat in a Food object. */
virtual double percent_fat() const = 0;
    /** Calculates the percent of carbohydrates in a Food object. */
virtual double percent_carbohydrates() const = 0;
 virtual ~Food() {} 

    // Functions
    double get_calories() const { return calories; }
    void set_calories(double cal) {
      calories = cal;
    }
};

#endif
