#include <iostream>
#include <string>
using namespace std;

int main() {
    string brakeName[2] = {"disc", "drum"};
    double brakeMTBF[2] = {4, 5};
    double brakeCost[2] = {15, 25};

    string engineName[2] = {"wankle", "conventional"};
    double engineMTBF[2] = {3, 6};
    double engineCost[2] = {1067, 1850};

    string suspensionName[2] = {"air", "oil"};
    double suspensionMTBF[2] = {9, 7};
    double suspensionCost[2] = {430, 320};

    string electricalName[2] = {"computer", "standard"};
    double electricalMTBF[2] = {2, 4};
    double electricalCost[2] = {130, 40};

    double cheapestCost = 999999;
    double longestMTBF = -1;
    double bestCostPerYear = 999999;

    string cheapestSystem;
    string longestSystem;
    string bestValueSystem;

    for (int b = 0; b < 2; b++) {
        for (int e = 0; e < 2; e++) {
            for (int s = 0; s < 2; s++) {
                for (int el = 0; el < 2; el++) {

                    double totalCost =
                        brakeCost[b] + engineCost[e] +
                        suspensionCost[s] + electricalCost[el];

                    double totalMTBF = 1.0 /
                        (1.0 / brakeMTBF[b] +
                         1.0 / engineMTBF[e] +
                         1.0 / suspensionMTBF[s] +
                         1.0 / electricalMTBF[el]);

                    double costPerYear = totalCost / totalMTBF;

                    string system =
                        brakeName[b] + " brakes, " +
                        engineName[e] + " engine, " +
                        suspensionName[s] + " suspension, " +
                        electricalName[el] + " electrical";

                    if (totalCost < cheapestCost) {
                        cheapestCost = totalCost;
                        cheapestSystem = system;
                    }

                    if (totalMTBF > longestMTBF) {
                        longestMTBF = totalMTBF;
                        longestSystem = system;
                    }

                    if (costPerYear < bestCostPerYear) {
                        bestCostPerYear = costPerYear;
                        bestValueSystem = system;
                    }
                }
            }
        }
    }

    cout << "Cheapest system: " << cheapestSystem
         << " ($" << cheapestCost << ")" << endl;

    cout << "Longest MTBF system: " << longestSystem
         << " (" << longestMTBF << " years)" << endl;

    cout << "Lowest cost per failure-free year: " << bestValueSystem
         << " ($" << bestCostPerYear << " per year)" << endl;

    return 0;
}