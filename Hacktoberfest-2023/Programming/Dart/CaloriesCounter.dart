import 'dart:io';

void main() {
  var foodItems = <String, int>{};
  int totalCalories = 0;

  print("Calorie Counter");
  while (true) {
    print("\nMenu:");
    print("1. Add Food Item");
    print("2. View Food Items");
    print("3. Calculate Total Calories");
    print("4. Exit");
    stdout.write("Enter your choice: ");
    var choice = int.tryParse(stdin.readLineSync() ?? '');

    switch (choice) {
      case 1:
        addFoodItem(foodItems);
        break;
      case 2:
        viewFoodItems(foodItems);
        break;
      case 3:
        calculateTotalCalories(foodItems, totalCalories);
        break;
      case 4:
        print("Exiting the program.");
        return;
      default:
        print("Invalid choice. Please try again.");
    }
  }
}

void addFoodItem(Map<String, int> foodItems) {
  stdout.write("Enter the name of the food item: ");
  var itemName = stdin.readLineSync() ?? '';
  stdout.write("Enter the calorie count for $itemName: ");
  var calorieCount = int.tryParse(stdin.readLineSync() ?? '');

  if (calorieCount != null) {
    foodItems[itemName] = calorieCount;
    print("$itemName added with $calorieCount calories.");
  } else {
    print("Invalid calorie count. Please enter a valid number.");
  }
}

void viewFoodItems(Map<String, int> foodItems) {
  print("\nFood Items:");
  if (foodItems.isEmpty) {
    print("No food items added yet.");
  } else {
    foodItems.forEach((itemName, calorieCount) {
      print("$itemName - $calorieCount calories");
    });
  }
}

void calculateTotalCalories(Map<String, int> foodItems, int totalCalories) {
  if (foodItems.isEmpty) {
    print("No food items added yet.");
  } else {
    totalCalories = foodItems.values.reduce((a, b) => a + b);
    print("\nTotal Calories: $totalCalories");
  }
}
