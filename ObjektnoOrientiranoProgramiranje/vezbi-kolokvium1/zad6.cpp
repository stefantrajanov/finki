#include<iostream>
#include <cstring>

using namespace std;

typedef struct {
    char pathway[70];
    float predictedKMPassed;
    int capacity;

} Train;

typedef struct {
    char currentCity[100];
    Train trains[30];
    int numberOfTrains;

} RailwayStation;

void shortestPath(RailwayStation *stations, int n, char *city) {
    int theStationIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (strcmp(stations[i].currentCity, city) == 0) {
            theStationIndex = i;
        }
    }
    if (theStationIndex == -1) {
        cout << "Nema";
        return;
    }

    float min = 0;
    int trainIndex = 0;
    for (int i = 0; i < stations[theStationIndex].numberOfTrains; ++i) {
        if (min == 0){
            min = stations[theStationIndex].trains[i].predictedKMPassed;
            trainIndex = i;
            continue;
        }

        if (min >= stations[theStationIndex].trains[i].predictedKMPassed) {
            min = stations[theStationIndex].trains[i].predictedKMPassed;
            trainIndex = i;
        }
    }

    cout << "Najkratka relacija: " << stations[theStationIndex].trains[trainIndex].pathway << " ("<<
    min << " km)";
}

int main() {

    int n;
    cin >> n; //se cita brojot na zelezlnichki stanici

    RailwayStation station[100];
    for (int i = 0; i < n; i++) {
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin >> station[i].currentCity;
        cin >> station[i].numberOfTrains;
        for (int j = 0; j < station[i].numberOfTrains; ++j) {
            cin >> station[i].trains[j].pathway;
            cin >> station[i].trains[j].predictedKMPassed;
            cin >> station[i].trains[j].capacity;
        }
    }

    char city[25];
    cin >> city;

    shortestPath(station, n, city);
    return 0;
}
