#pragma once

#include <vector>
#include <string>
#include <cstdint>

enum class CellState : uint8_t {
    Blank,
    White,
    Black
};

struct Nonogram {
    int board_size;
    std::vector<std::vector<int>> hint_rows;
    std::vector<std::vector<int>> hint_cols;
    std::vector<CellState> cells;
};

