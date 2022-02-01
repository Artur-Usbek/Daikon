
 //https://eigen.tuxfamily.org/dox/structEigen_1_1IOFormat.html

#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
void saveMatrix(std::string fileName, T matrix)
{
    const static Eigen::IOFormat CSVFormat(Eigen::FullPrecision, Eigen::DontAlignCols, ", ", "\n");

    std::ofstream file(fileName);
    if (file.is_open())
    {
        file << matrix.format(CSVFormat);
        file.close();
    }
};


Eigen::MatrixXd readMatrix(std::string fileToOpen)
{
    std::vector<double> matrixEntries;
    std::ifstream matrixDataFile(fileToOpen);
    std::string matrixRowString;
    std::string matrixEntry;
    int matrixRowNumber = 0;

    while (getline(matrixDataFile, matrixRowString))
    {
        std::stringstream matrixRowStringStream(matrixRowString);
        while (getline(matrixRowStringStream, matrixEntry, ',')) 
        {
            matrixEntries.push_back(stod(matrixEntry));
        }
        matrixRowNumber++;
    }
    return Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>>(matrixEntries.data(), matrixRowNumber, matrixEntries.size() / matrixRowNumber);
}