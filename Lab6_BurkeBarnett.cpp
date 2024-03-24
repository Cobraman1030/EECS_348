#include <iostream>
#include <fstream>
#include <string>
const int max = 100;
void readerbot(int matrix[max][max], int& size, const std::string& filename) {
    
    std::ifstream file(filename);
    if (file) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } 
}
void printing_press(const int matrix[max][max], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void addition(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m_one[i][j] + m_two[i][j];
        }
    }
}
void mutiplier(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += m_one[i][k] * m_two[k][j];
            }
        }
    }
}
void contractor(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m_one[i][j] - m_two[i][j];
        }
    }
}
void freshupdater(int matrix[max][max], int size) {
    
    int row, col, value;
    std::cout << "Enter row index: ";
    std::cin >> row;
    std::cout << "Enter column index: ";
    std::cin >> col;
    std::cout << "Enter new value: ";
    std::cin >> value;

    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;
    } else {
        std::cout << "Invalid row or column index." << std::endl;
    }
}
void maximizer(const int matrix[max][max], int size) {
    
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    
    std::cout << "Max value in the matrix: " << maxVal << std::endl;
}
void composer(const int matrix[max][max], int transposed[max][max], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}



int main() {
    int size;
    int m_one[max][max];
    int m_two[max][max];
    int result[max][max];
    int transposed[max][max];
    readerbot(m_one, size, "matrix_input.txt");
    readerbot(m_two, size, "matrix_input.txt");

    std::cout << "Matrix A: " << std::endl;
    printing_press(m_one, size);
    std::cout << "Matrix B: " << std::endl;
    printing_press(m_two, size);

    if (size > 0) { 
        addition(m_one, m_two, result, size);
        std::cout << "Matrix Sum (A + B): " << std::endl;
        printing_press(result, size);

        mutiplier(m_one, m_two, result, size);
        std::cout << "Matrix Product (A * B): " << std::endl;
        printing_press(result, size);

        contractor(m_one, m_two, result, size);
        std::cout << "Matrix Difference (A - B): " << std::endl;
        printing_press(result, size);

        freshupdater(m_one, size);
        std::cout << "Updated Matrix A: " << std::endl;
        printing_press(m_one, size);

        maximizer(m_one, size);   

        composer(m_one, transposed, size);
        std::cout << "Transposed Matrix A: " << std::endl;
        printing_press(transposed, size);
    }
    return 0;
}