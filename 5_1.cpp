#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to store ad slot details
struct AdSlot {
    double duration;
    double price;

    // Calculate value per second
    double valuePerSecond() const {
        return price / duration;
    }
};

// Custom comparator to sort slots by highest value per second
bool compare(AdSlot a, AdSlot b) {
    return a.valuePerSecond() > b.valuePerSecond();
}

// Function to maximize revenue
double maximizeRevenue(vector<AdSlot>& ads, double availableTime) {
    // Sort ads by value per second in descending order
    sort(ads.begin(), ads.end(), compare);

    double totalRevenue = 0.0;

    for (const auto& ad : ads) {
        if (availableTime >= ad.duration) {
            // Take full slot
            totalRevenue += ad.price;
            availableTime -= ad.duration;
        } else {
            // Take fraction of the slot
            totalRevenue += ad.price * (availableTime / ad.duration);
            break;  // No more available time
        }
    }

    return totalRevenue;
}

int main() {
    vector<AdSlot> ads = { {10, 100}, {20, 180}, {15, 150}, {30, 300} };
    double availableTime = 25;  // Maximum available ad duration in seconds

    double maxRevenue = maximizeRevenue(ads, availableTime);
    cout << "Maximum Revenue: $" << maxRevenue << endl;

    return 0;
}
