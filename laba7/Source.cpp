#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue> // î÷åðåäü
#include <string>


using namespace std;




void BFS1(int** mas, int DIST[10], int start)
{
    queue<int> Queue;
    int nodes[7]; // âåðøèíû ãðàôà
    //for (int i = 0; i < 7; i++)

    Queue.push(start); // ïîìåùàåì â î÷åðåäü ïåðâóþ âåðøèíó
    DIST[start] = 0; // èñõîäíî âñå âåðøèíû ðàâíû 1000
    while (!Queue.empty())
    { // ïîêà î÷åðåäü íå ïóñòà
        start = Queue.front(); // èçâëåêàåì âåðøèíó
        Queue.pop();
        cout << start << endl; // âûâîäèì íîìåð âåðøèíû
        for (int j = 0; j < 7; j++)
        { // ïðîâåðÿåì äëÿ íåå âñå ñìåæíûå âåðøèíû
            if (mas[start][j] == 1 && DIST[j] > DIST[start] + mas[start][j])
            { // åñëè âåðøèíà ñìåæíàÿ è íå îáíàðóæåíà
                Queue.push(j); // äîáàâëÿåì åå â î÷åðåäü
                //nodes[j] = 1; // îòìå÷àåì âåðøèíó êàê îáíàðóæåííóþ
                DIST[j] = DIST[start] + mas[start][j];
            }
        }

    }
}


int param(int argc, char* argv[]) {
    int** graph;



    char p1[5];
    int start;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << "-é àðãóìåíò: " << argv[i] << '\n';
    }



    //char* a = argv[2];


    int size = stoi(argv[2]);
    //cout << size;
    graph = (int**)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        graph[i] = (int*)malloc(size * sizeof(int));
    }

    if (strcmp(argv[1], "OB") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                graph[i][j] = rand() % 5;
            }
        }
    }

    if (strcmp(argv[1], "ON") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                graph[i][j] = rand() % 2;
            }
        }
    }

    if (strcmp(argv[1], "NO") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i + 1; j++) {
                int num = rand() % 5;
                graph[i][j] = num;
                graph[j][i] = num;
            }
        }
    }

    if (strcmp(argv[1], "NN") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i + 1; j++) {
                int num = rand() % 2;
                graph[i][j] = num;
                graph[j][i] = num;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
    cout << "Ââåäèòå íà÷àëüíóþ âåðøèíó \n";

    cin >> start;


    int DIST[10];

    for (int i = 0; i < size; i++) {

        DIST[i] = 1000;
    }
    cout << "îáõîä â øèðèíó\n";

    BFS1(graph, DIST, start);

    for (int i = 0; i < size; i++) {

        printf("ðàññîÿíèå îò %d äî %d = %d\n", start, i, DIST[i]);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");



    //cin >> p1;

    std::cout << "Â ïðîãðàììå àðãóìåíòîâ: " << argc << " \n\n";

    if (argc > 1)
    {
        param(argc, argv);
    }

    else
    {
        cout << "Ââåäèòå òèï ãðàôà (ÎÂ èëè NN èëè NO èëè ON) \n";
        std::cout << "Óêàæèòå àðãóìåíòû. ";
        param(argc, argv);
    }
    std::cout << '\n';

    system("pause");
}