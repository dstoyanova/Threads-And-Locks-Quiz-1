//
//  main.cpp
//  Quiz-1
//
//  Created by Desislava Stoyanova on 9/16/15.
//  Copyright (c) 2015 Desislava Stoyanova. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int* buffer;

void sum(int* array,size_t size,int index) {
    buffer[index] = 0;
    for (int i=0; i<size; i++) {
        buffer[index] += array[i];
    }
}

int main(int argc, const char * argv[]) {
    // Create the matrix
    cout << "Enter n: ";
    size_t n; cin >> n;
    
    int** matrix = new int*[n];
    for (int i=0; i<n; i++) {
        matrix[i] = new int[n];
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    
    // Creating threads
    buffer = new int[n];
    vector<thread> threads;
    
    for (int i=0; i<n; i++) {
        threads.push_back(thread(sum,matrix[i],n,i));
    }

    for (auto &t : threads) {
        t.join();
    }
    
    // Get the final result
    int result = 0;

    for (int i=0; i<n; i++)
        result += buffer[i];
    
    cout << result << endl;
    
    // Deallocating the memory
    delete [] buffer;
    
    for (int i=0; i<n; i++) {
        delete [] matrix[i];
    }
    
    delete [] matrix;
    
    return 0;
}