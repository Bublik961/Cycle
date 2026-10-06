/*************************************************
 * Автор: Тенц Ангелина                          *
 * Вариант: 7                                    *
 * Название: Циклы с предусловием и постусловием *
 *************************************************/

#include <iostream>
#include <cmath>

using namespace std; 

int main() {
    const int firstStep = 10;
    const int secondStep = 50;
    const int start = 10;
    const int changePoint = 50;
    const int finish = 250;
    double chamberVolume, initialPressure, pumpVolume, residualPressure;
    int pumpStrokes, stepIndex;

    cout << "Enter chamber volume: ";
    cin >> chamberVolume;

    cout << "Enter gas pressure (mm Hg): ";
    cin >> initialPressure;
    
    cout << "Enter pump volume: ";
    cin >> pumpVolume;

    cout << "\nPump strokes \tResidual pressure, mm Hg";

    pumpStrokes = start;
    stepIndex = 0;

    do {
        residualPressure = initialPressure * pow((chamberVolume / (chamberVolume + pumpVolume)), pumpStrokes);
        cout << "\n" << pumpStrokes << "\t\t\t" << residualPressure;
        ++stepIndex;
        pumpStrokes = start + stepIndex * firstStep;
    } while (pumpStrokes <= changePoint);
    
    stepIndex = 1;
    pumpStrokes = changePoint + stepIndex * secondStep;

    while (pumpStrokes <= finish) {
        residualPressure = initialPressure * pow((chamberVolume / (chamberVolume + pumpVolume)), pumpStrokes);
        cout << "\n" << pumpStrokes << "\t\t\t" << residualPressure;
        ++stepIndex;
        pumpStrokes = changePoint + stepIndex * secondStep;
    }

    return 0;
}