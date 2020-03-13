// MediumLevel.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Train {
    int number;
    int ArrivalTime;
    int DepartureTime;
    string direction;
    int distance;
    bool TimeIsCorrect();
};

bool Train::TimeIsCorrect() {
    bool result = false;

    if ((ArrivalTime > DepartureTime) &&(DepartureTime > 0) && (DepartureTime < 24)&& (ArrivalTime > 0) && (ArrivalTime < 24)) {
        bool result = true;
    }
    return result;
}

void AverageSpeed(Train *trains, const int *k) {
    for (int i = 0; i < *k; i++) {
        cout << "\nSpeed of " << i << " train: "<<trains[i].distance/(trains[i].ArrivalTime - trains[i].DepartureTime);
    }
}

int main()
{
    const int k = 2;
    Train trains[k];

    for (int i = 0;i < k;i++) {
        cout << "\nInput number: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> trains[i].number;
        do
        {
            cout << "\nInput departure time: ";
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> trains[i].DepartureTime;

            cout << "\nInput arrival time: ";
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> trains[i].ArrivalTime;

        } while (!trains[i].TimeIsCorrect());

        cout << "\nInput direction: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> trains[i].direction;
        cout << "\nInput distance: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> trains[i].distance;

    }

    AverageSpeed(trains,&k);

    


}
