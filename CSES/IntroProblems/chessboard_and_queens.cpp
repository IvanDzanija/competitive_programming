#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using ll = int64_t;

ll res = 0;
void generateSolutions(std::vector<std::string> &board, int row,
                       std::vector<int> &occCol, std::vector<int> &occDiag1,
                       std::vector<int> &occDiag2) {
    if (row == 8) {
        ++res;
        return;
    } else {
        for (int i = 0; i < 8; ++i) {
            if (board.at(row).at(i) == '*' || occCol.at(i) == 1 ||
                occDiag1.at(row + i) == 1 || occDiag2.at(row - i + 8) == 1)
                continue;
            else {
                occCol.at(i) = 1;
                occDiag1.at(row + i) = 1;
                occDiag2.at(row - i + 8) = 1;
                generateSolutions(board, row + 1, occCol, occDiag1, occDiag2);
                occCol.at(i) = 0;
                occDiag1.at(row + i) = 0;
                occDiag2.at(row - i + 8) = 0;
            }
        }
    }
}

int main(void) {
    std::vector<std::string> board;
    for (int i = 0; i < 8; ++i) {
        std::string row;
        std::cin >> row;
        board.push_back(row);
    }
    std::vector<int> occCol(8, 0);
    std::vector<int> occDiag1(16, 0);
    std::vector<int> occDiag2(16, 0);

    generateSolutions(board, 0, occCol, occDiag1, occDiag2);
    std::cout << res << std::endl;

    return 0;
}
